#include "GingerbreadGroup.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace {
template <typename Predicate>
void removeMembers(std::vector<std::shared_ptr<GingerbreadMan>>& members,
                   int& nextIndex, Predicate shouldRemove) {
    // Find the first surviving attacker in the original turn order.
    std::shared_ptr<GingerbreadMan> nextAttacker;
    for (std::size_t offset = 0; offset < members.size(); ++offset) {
        const auto index = (static_cast<std::size_t>(nextIndex) + offset) % members.size();
        if (!shouldRemove(members[index])) {
            nextAttacker = members[index];
            break;
        }
    }

    members.erase(std::remove_if(members.begin(), members.end(), shouldRemove), members.end());
    nextIndex = 0;
    if (nextAttacker) {
        const auto next = std::find(members.begin(), members.end(), nextAttacker);
        nextIndex = static_cast<int>(next - members.begin());
    }
}
}

GingerbreadGroup::GingerbreadGroup(int maxSize)
    : maxSize(maxSize), currIndex(0) {
    if (maxSize < 3 || maxSize > 9) {
        throw std::invalid_argument("Group capacity must be between 3 and 9");
    }
}

std::vector<int> GingerbreadGroup::attack(std::vector<Element>& types) {
    std::vector<int> damages(types.size(), 0);
    if (queue.empty()) {
        return damages;
    }

    const int memberCount = static_cast<int>(queue.size());
    currIndex %= memberCount;
    const auto& attacker = queue[currIndex];
    const auto positions = attacker->getInteractPositions();
    const std::size_t sectionSize = types.size() / 3;

    for (std::size_t i = 0; i < types.size(); ++i) {
        if (sectionSize != 0) {
            Position enemyPosition = Position::Back;
            if (i < sectionSize) {
                enemyPosition = Position::Front;
            } else if (i < 2 * sectionSize) {
                enemyPosition = Position::Middle;
            }
            if (std::find(positions.begin(), positions.end(), enemyPosition) == positions.end()) {
                continue;
            }
        }
        damages[i] = attacker->attack(types[i]);
    }

    currIndex = (currIndex + 1) % memberCount;
    return damages;
}

void GingerbreadGroup::onHit(std::vector<int>& damages) {
    if (damages.size() != queue.size()) {
        throw std::invalid_argument("Damage list must match group size");
    }
    for (std::size_t i = 0; i < queue.size(); ++i) {
        queue[i]->onHit(damages[i]);
    }
    removeDeadGingerbreadMan();
}

void GingerbreadGroup::addGingerbreadMan(std::shared_ptr<GingerbreadMan> gingerbreadMan) {
    if (!gingerbreadMan) {
        throw std::invalid_argument("Group member cannot be null");
    }

    const auto name = gingerbreadMan->getName();
    const auto position = gingerbreadMan->getPosition();
    int positionCount = 0;
    for (const auto& member : queue) {
        if (member->getName() == name) {
            throw std::invalid_argument("Group member name already exists");
        }
        if (member->getPosition() == position) {
            ++positionCount;
        }
    }

    const int sectionSize = maxSize / 3;
    const int positionLimit = position == Position::Back ? maxSize - 2 * sectionSize : sectionSize;

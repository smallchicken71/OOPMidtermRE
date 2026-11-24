#include "FrontGingerbreadMan.hpp"

FrontGingerbreadMan::FrontGingerbreadMan(
    std::string name, Element type, int damage, int defense, int health,
    float critDamage, int maxCritCount, int maxDodgeCount)
    : GingerbreadMan(name, type, Position::Back, damage, defense,
                     health, critDamage, maxCritCount, maxDodgeCount) {
}

void FrontGingerbreadMan::defenseBuff() {
    if (damage < defense) {
        defense*=1.1f;
    }
}
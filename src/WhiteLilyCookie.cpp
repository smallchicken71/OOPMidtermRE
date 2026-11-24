#include "WhiteLilyCookie.hpp"

WhiteLilyCookie::WhiteLilyCookie()
    : MiddleGingerbreadMan("White Lily Cookie", Element::Plant,
                          100, 100, 1500, 0.2f, 2) {
}

int WhiteLilyCookie::attack(Element enemyType) {
    const float crit = isCriticalHit() ? critDamage : 0.0f;
    return static_cast<int>(
        (1.0f + crit + elementalAttack(enemyType)) * damage
        + crit * currHealth
    );
}

bool WhiteLilyCookie::onHit(int incomingDamage) {
    const int realDamage = incomingDamage - (defense + damage);
    const bool noHealthLost = applydamage(realDamage);
    criticalBuff();
    return noHealthLost;
}
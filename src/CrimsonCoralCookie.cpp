#include "CrimsonCoralCookie.hpp"


CrimsonCoralCookie::CrimsonCoralCookie()
    :FrontGingerbreadMan("Crimson Coral Cookie",Element::Water,250,500,100,0.5,5,10){
}

int CrimsonCoralCookie::attack(Element enemyType) {
    float crit = 0.0f;
    if (isCriticalHit()) {
        crit = critDamage;
    }
    const int attackDamage = static_cast<int>(
        (1.0f + crit + elementalAttack(enemyType)) * damage + defense + health
    );

    defenseBuff();
    return attackDamage;
}

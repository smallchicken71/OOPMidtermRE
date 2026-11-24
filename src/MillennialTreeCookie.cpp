#include "MillennialTreeCookie.hpp"

MillennialTreeCookie::MillennialTreeCookie()
    :FrontGingerbreadMan("Millennial Tree Cookie",Element::Plant,200,150,1000){
}

void MillennialTreeCookie::levelUp(){
    ++level;
    damage+=150;
    defense+=150;
    health+=150;
    currHealth=health;
}

int MillennialTreeCookie::attack(Element enemyType) {
    float crit = 0.0f;
    if (isCriticalHit()) {
        crit = critDamage;
    }

    const double healthRatio = static_cast<double>(currHealth) / health;
    return static_cast<int>(
        (1.0 + crit + healthRatio + elementalAttack(enemyType)) * damage + 25
    );
}

bool MillennialTreeCookie::onHit(int incomingDamage){
    const int realDamage = static_cast<int>(incomingDamage - defense * (1 +((1.0 * currHealth) / health) ));
    defenseBuff();
    return applydamage(realDamage);
}
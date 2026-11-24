#include "MillennialTreeCookie.hpp"

MillennialTreeCookie::MillennialTreeCookie()
    :FrontGingerbreadMan("Millennial Tree Cookie",Element::Plant,200,150,1000){
}

void MillennialTreeCookie::levelUp(){
    damage+=150;
    defense+=150;
    health+=150;
}

int MillennialTreeCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    return static_cast<int>(1 + crit + (1.0 * currHealth) / health + elementalAttack(enemyType)) * damage + 25;
}

bool MillennialTreeCookie::onHit(int incomingDamage){
    const int realDamage = static_cast<int>(incomingDamage - defense * (1 +((1.0 * currHealth) / health) ));
    defenseBuff();
    return applydamage(realDamage);
}
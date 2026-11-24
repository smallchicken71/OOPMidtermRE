#include "BurningSpiceCookie.hpp"

BurningSpiceCookie::BurningSpiceCookie()
    :FrontGingerbreadMan("Burning Spice Cookie",Element::Fire,200,80,1000){
}

void BurningSpiceCookie::levelUp(){
    damage+=250;
    critDamage+=0.5f;
    health+=220;
}

int BurningSpiceCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    return static_cast<int>(1 + crit + elementalAttack(enemyType)) * (damage + 25);
}


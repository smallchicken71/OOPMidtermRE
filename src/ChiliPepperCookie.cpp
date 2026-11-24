#include "ChiliPepperCookie.hpp"


ChiliPepperCookie::ChiliPepperCookie()
    :MiddleGingerbreadMan("Chili Pepper Cookie",Element::Fire,200,100,900){
}

void ChiliPepperCookie::levelUp(){
    ++level;
    damage+=200;
    defense+=100;
    health+=100;
    currHealth=health;

    criticalBuff();
}

int ChiliPepperCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    return static_cast<int>(1 + crit + (1.0 * currHealth / health) + elementalAttack(enemyType)) * damage;
}


#include "SeaFairyCookie.hpp"


SeaFairyCookie::SeaFairyCookie()
    :MiddleGingerbreadMan("Millennial Tree Cookie",Element::Water,200,300,1000,0.3f){
}

void SeaFairyCookie::levelUp(){
    ++level;
    damage+=100;
    defense+=150;
    health+=160;

    if(maxCritCount>1){
        maxCritCount-=1;
        critCount=0;
    }
    criticalBuff();
}

int SeaFairyCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    return static_cast<int>(1 + crit + elementalAttack(enemyType)) * damage + critDamage * defense;
}


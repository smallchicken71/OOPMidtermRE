#include "WhiteLilyCookie.hpp"

WhiteLilyCookie::WhiteLilyCookie()
    :MiddleGingerbreadMan("White Lily Cookie",Element::Plant,100,150,1500,0.2,2){
}

int WhiteLilyCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
         return static_cast<int>(1 + crit + elementalAttack(enemyType)) * damage + critDamage * currHealth;
    }
}

bool WhiteLilyCookie::onHit(int incomingDamage){
    const int realDamage =static_cast<int>( incomingDamage - defense);
    criticalBuff();
    return applydamage(realDamage);
}
#include "CrimsonCoralCookie.hpp"


CrimsonCoralCookie::CrimsonCoralCookie()
    :FrontGingerbreadMan("Crimson Coral Cookie",Element::Water,250,500,100,0.5,5,10){
}

int CrimsonCoralCookie::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    defenseBuff();
    return static_cast<int>(1 + crit + elementalAttack(enemyType)) * damage + defense + health;
    
}

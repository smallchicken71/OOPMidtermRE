#include "SilverbellCookie.hpp"

SilverbellCookie::SilverbellCookie()
    :BackGingerbreadMan("Silverbell Cookie",Element::Plant,200,150,900,0.8,3,8){
}

void SilverbellCookie::levelUp(){
    ++level;
    damage+=150;
    defense+=50;
    health+=150;
    currHealth=health;
    keepHealingBuff();
}



bool SilverbellCookie::onHit(int incomingDamage){
    const int realDamage =static_cast<int>( incomingDamage - defense * (1 + level / 100.0));
    return applydamage(realDamage);
}
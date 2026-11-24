#include "FireSpiritCookie.hpp"

FireSpiritCookie::FireSpiritCookie()
    :BackGingerbreadMan("Fire Spirit Cookie",Element::Fire,500,20,200,0.5,2,7){
}

void FireSpiritCookie::levelUp(){
    ++level;
    damage+=100;
    critDamage+=0.1f;
    health+=20;
    defense+=5;
    currHealth=health;
    keepHealingBuff();
}

#include "SeltzerCookie.hpp"


SeltzerCookie::SeltzerCookie()
    :BackGingerbreadMan("Millennial Tree Cookie",Element::Water,200,450,700,0.7f,2,3){
}


bool SeltzerCookie::onHit(int incomingDamage){
    const int realDamage = static_cast<int>(incomingDamage - defense * (1 + level / 100.0));
    keepHealingBuff();
    return applydamage(realDamage);
}
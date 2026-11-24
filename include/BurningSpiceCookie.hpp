#ifndef BURNINGSPICECOOKIE_HPP
#define BURNINGSPICECOOKIE_HPP

#include "FrontGingerbreadMan.hpp"

class BurningSpiceCookie final : public FrontGingerbreadMan {
public:
    BurningSpiceCookie();
    virtual void levelUp() override;
    virtual int attack(Element enemyType) override;
};

#endif

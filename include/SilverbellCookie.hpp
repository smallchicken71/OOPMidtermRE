#ifndef SILVERBELLCOOKIE_HPP
#define SILVERBELLCOOKIE_HPP

#include "BackGingerbreadMan.hpp"

class SilverbellCookie final : public BackGingerbreadMan {
public:
    SilverbellCookie();
    virtual void levelUp() override;
    virtual bool onHit(int incomingDamage) override;
};

#endif

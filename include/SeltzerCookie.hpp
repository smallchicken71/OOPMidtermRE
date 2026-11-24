#ifndef SELTZERCOOKIE_HPP
#define SELTZERCOOKIE_HPP

#include "BackGingerbreadMan.hpp"

class SeltzerCookie final : public BackGingerbreadMan {
public:
    SeltzerCookie();
    virtual bool onHit(int incomingDamage) override;
};

#endif

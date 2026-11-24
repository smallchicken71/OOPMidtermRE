#ifndef CHILIPEPPERCOOKIE_HPP
#define CHILIPEPPERCOOKIE_HPP

#include "MiddleGingerbreadMan.hpp"

class ChiliPepperCookie final : public MiddleGingerbreadMan {
public:
    ChiliPepperCookie();
    virtual void levelUp() override;
    virtual int attack(Element enemyType) override;
};

#endif

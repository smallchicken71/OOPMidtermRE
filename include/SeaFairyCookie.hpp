#ifndef SEAFAIRYCOOKIE_HPP
#define SEAFAIRYCOOKIE_HPP

#include "MiddleGingerbreadMan.hpp"

class SeaFairyCookie final : public MiddleGingerbreadMan {
public:
    SeaFairyCookie();
    virtual void levelUp() override;
    virtual int attack(Element enemyType) override;
};

#endif

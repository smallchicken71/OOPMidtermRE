#ifndef CRIMSONCORALCOOKIE_HPP
#define CRIMSONCORALCOOKIE_HPP

#include "FrontGingerbreadMan.hpp"

class CrimsonCoralCookie final : public FrontGingerbreadMan {
public:
    CrimsonCoralCookie();
    virtual int attack(Element enemyType) override;
};

#endif

#include "Character.hpp"
Character::Character(std::string name, int damage, int defense, int health, int maxCritCount, int maxDodgeCount)
    :name(std::move(name)),
    level(1),
    damage(damage),
    defense(defense),
    health(health),
    currHealth(health),
    maxCritCount(maxCritCount),
    maxDodgeCount(maxDodgeCount),
    critCount(0),
    dodgeCount(0){
}

std::string Character::getName()const{
    return name;
}

int Character::getLevel() const{
    return level;
}

int Character::getDamage() const{
    return damage;
}

int Character::getDefense() const{
    return defense;
}

int Character::getHealth() const{
    return health;
}

int Character::getCurrHealth() const{
    return currHealth;
}

int Character::getMaxCritCount()const{
    return maxCritCount;
}

int Character::getMaxDodgeCount()const{
    return maxDodgeCount;
}

bool Character::isCriticalHit(){
    critCount+=1;
    if(critCount == maxCritCount){
        critCount=0;
        return true;
    }
    return false;
}

bool Character::isDodged(){
    dodgeCount+=1;
    if(dodgeCount == maxDodgeCount){
        dodgeCount=0;
        return true;
    }
    return false;
}
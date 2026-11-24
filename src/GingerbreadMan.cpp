#include "GingerbreadMan.hpp"

GingerbreadMan::GingerbreadMan(std::string name, Element type, Position pos, int damage, int defense, int health, float critDamage, int maxCritCount, int maxDodgeCount)
    :Character(name, damage, defense, health,maxCritCount,maxDodgeCount),
    type(type),
    pos(pos),
    critDamage(critDamage){
    }

void GingerbreadMan::levelUp(){
    level+=1;
    damage+=100;
    defense+=100;
    health+=100;
    currHealth=health;
}

float GingerbreadMan::elementalAttack(Element enemyType){
    if (type == Element::Water && enemyType == Element::Fire) {
        return 0.7f;
    }

    if (type == Element::Fire && enemyType == Element::Plant) {
        return 1.0f;
    }

    if (type == Element::Plant && enemyType == Element::Water) {
        return 0.5f;
    }

    return 0.0f;
}

int GingerbreadMan::attack(Element enemyType){
    float crit=0.0f;
    if(isCriticalHit()){
        crit=critDamage;
    }
    return static_cast<int>((1.0f + crit + elementalAttack(enemyType)) * damage);
}


bool GingerbreadMan::onHit(int incomingDamage){
    return applydamage(incomingDamage-defense);
}

bool GingerbreadMan::applydamage(int realdamage){
    if(isDodged()||realdamage<=0){
        return true;
    }
    currHealth-=realdamage;
    return false;
}

std::vector<Position> GingerbreadMan::getInteractPositions() const{
        switch (pos) {
    case Position::Front:
        return {Position::Front};
    case Position::Middle:
        return {Position::Front, Position::Middle};
    case Position::Back:
        return {Position::Middle, Position::Back};
    }

    return {};
}

Position GingerbreadMan::getPosition() const{
    return pos;
}

Element GingerbreadMan::getElementType() const{
    return type;
}

float GingerbreadMan::getCritDamage() const{
    return critDamage;
}
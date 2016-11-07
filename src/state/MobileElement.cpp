/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MobileElement.h"
namespace state{
MobileElement::MobileElement(MobileTypeId mi):mobileId(mi)
{
    switch(mi)
    {
        case(JOUEUR):
            life=1;
            speed=0.1;
            break;
            
        case(NORMAL):
            life=1;
            speed=1;
            break;
        case(QUICK):
            life=1;
            speed=2;
            break;
        
    }
}
bool MobileElement::equals(const Element& other) const
{
//    if((this->x==other.getX())&&(this->y==other.getY())&&
//            (this->orientation==other.getOrientation()))
        return true;
    return false;
}
bool MobileElement::isStatic() const
{
    return false;
}
Direction MobileElement::getDirection() const
{
    return orientation;
}
int MobileElement::getSpeed() const
{
    return speed;
}
int MobileElement::getPosition() const
{
    return position;
}
int MobileElement::getColor() const
{
    return color;
}
MobileTypeId MobileElement::getMobileTypeId() const
{
    return mobileId;
}
void MobileElement::setDirection(Direction d)
{
    orientation=d;
}
void MobileElement::setSpeed(int s)
{
    this->speed=s;
}
void MobileElement::setPosition(int position)
{
    this->position=position;
}
void MobileElement::attack()
{
}
void MobileElement::beingattacked()
{
    this->life--;
}
void MobileElement::setMobileTypeId(MobileTypeId mi)
{
    mobileId=mi;
}
};
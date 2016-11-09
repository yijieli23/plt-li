/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Element.h"
namespace state{
Element::Element()
{
}

Element::~Element()
{
}
bool Element::equals(const Element& other) const
{
    if((this->x==other.getX())&&(this->y==other.getY()))
        return true;
    else return false;
}

int Element::getX() const
{
    return x;
}
int Element::getY() const
{
    return y;
}

int Element::getLife() const
{
    return life;
}
void Element::setX(int x)
{
    this->x=x;
}
void Element::setY(int y)
{
    this->y=y;
}

void Element::setLife(int lifenum)
{
    this->life=lifenum;
}
};
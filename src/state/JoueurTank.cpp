/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "JoueurTank.h"

namespace state{

JoueurTank::JoueurTank(int x,int y)
{
    this->x=x;
    this->y=y;
    life=1;
    speed=0.1;
}
bool JoueurTank::isJoueurTank()
{
    return true;
}

 Element* JoueurTank::clone() const
{
    return new JoueurTank(*this);
}
void JoueurTank::addlife(int lifenum)
{
    this->life+=lifenum;
}


};
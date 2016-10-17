/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "JoueurTank.h"

namespace state{

JoueurTank::JoueurTank()
{
    
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
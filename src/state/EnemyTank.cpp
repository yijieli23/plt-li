/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "EnemyTank.h"
namespace state{
EnemyTank::EnemyTank()
{
}
bool EnemyTank::isEnemyTank() const
{
    return true;
}
TypeId EnemyTank::getTypeId() const
{
    return ENEMYTANK;
}
 Element* EnemyTank::clone() const
{
    return new EnemyTank(*this);
}
void EnemyTank::setColor(int c)
{
    this->color=c;
}
};
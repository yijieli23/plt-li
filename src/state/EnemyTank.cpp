/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "EnemyTank.h"
namespace state{
EnemyTank::EnemyTank(int x,int y)
{
    this->x=x;
    this->y=y;
    this->orientation=SOUTH;
    life=1;
    speed=0.1;
}
void EnemyTank::init(std::vector<int>& level)
{
    level[this->x*15+this->y]=112;
}
bool EnemyTank::isEnemyTank() const
{
    return true;
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
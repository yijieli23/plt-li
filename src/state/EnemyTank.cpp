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

void EnemyTank::moveleft(std::vector<int>& level)
{
    this->orientation=EAST;
    level[this->x*15+this->y]=110;
    if(this->y-1>=0) 
    {
        if(level[this->x*15+this->y-1]==21)
        {
            level[this->x*15+this->y]=21;
            this->y=this->y-1;
            level[this->x*15+this->y]=110;
        }
    }
}
void EnemyTank::moveright(std::vector<int>& level)
{
    this->orientation=WEST;
    level[this->x*15+this->y]=114;
        if(this->y+1<=14)
    {
        if(level[this->x*15+this->y+1]==21)
        {
            level[this->x*15+this->y]=21;
            this->y=this->y+1;
            level[this->x*15+this->y]=114;
        }
    }
    
}
void EnemyTank::moveup(std::vector<int>& level)
{
    this->orientation=NORTH;
    level[this->x*15+this->y]=108;
    if(level[(this->x-1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x-1;
        level[this->x*15+this->y]=108;
    }
    
}
void EnemyTank::movedown(std::vector<int>& level)
{
    this->orientation=SOUTH;
    level[this->x*15+this->y]=112;
    if(level[(this->x+1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x+1;
        level[this->x*15+this->y]=112;
    }
    
}

};
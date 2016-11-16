/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "JoueurTank.h"
#include <unistd.h>
namespace state{

JoueurTank::JoueurTank()
{
    this->x=14;
    this->y=4;
    this->orientation=NORTH;
    life=1;
    speed=0.1;
}
void JoueurTank::init(std::vector<int>& level)
{
    level[this->x*15+this->y]=0;
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
void JoueurTank::wait()
{
    usleep(200000);
}

void JoueurTank::moveleft(std::vector<int>& level)
{
    this->orientation=EAST;
    level[this->x*15+this->y]=2;
    if(this->y-1>=0)
    {    
        if(level[this->x*15+this->y-1]==21)
        {
            level[this->x*15+this->y]=21;
            this->y=this->y-1;
            level[this->x*15+this->y]=2;
            wait();
        }
    }
}
void JoueurTank::moveright(std::vector<int>& level)
{
    this->orientation=WEST;
    level[this->x*15+this->y]=6;
        if(this->y+1<=14)
    {
        if(level[this->x*15+this->y+1]==21)
        {
            level[this->x*15+this->y]=21;
            this->y=this->y+1;
            level[this->x*15+this->y]=6;
        }
    }
    wait();
}
void JoueurTank::moveup(std::vector<int>& level)
{
    this->orientation=NORTH;
    level[this->x*15+this->y]=0;
    if(level[(this->x-1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x-1;
        level[this->x*15+this->y]=0;
    }
    wait();
}
void JoueurTank::movedown(std::vector<int>& level)
{
    this->orientation=SOUTH;
    level[this->x*15+this->y]=4;
    if(level[(this->x+1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x+1;
        level[this->x*15+this->y]=4;
    }
    wait();
}

};
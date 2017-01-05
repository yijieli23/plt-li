/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Wood.h"
namespace state{

Wood::Wood(int x,int y)
{
    this->x=x;
    this->y=y;
    life=1;
}
Element* Wood::clone() const
{
    return new Wood(*this);
}
void Wood::beingattacked()
{
    this->life--;
}

void Wood::init(std::vector<int>& level)
{
    level[this->x*15+this->y]=16;
}

};
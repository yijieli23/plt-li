/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "House.h"
namespace state{

House::House()
{
    this->x=14;
    this->y=7;
    life=1;
}
Element* House::clone() const
{
    return new House(*this);
}
void House::beingattacked()
{
    this->life--;
}
void House::init(std::vector<int>& level)
{
    level[this->x*15+this->y]=69;
}



};

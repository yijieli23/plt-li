/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "House.h"
using namespace state;

House::House()
{
    
}
Element* House::clone() const
{
    return new House(*this);
}
void House::beingattacked()
{
    this->life--;
}

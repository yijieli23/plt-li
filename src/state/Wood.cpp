/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Wood.h"
using namespace state;

Wood::Wood()
{
    
}
Element* Wood::clone() const
{
    return new Wood(*this);
}
void Wood::beingattacked()
{
    this->life--;
}
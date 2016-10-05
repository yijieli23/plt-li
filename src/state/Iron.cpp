/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Iron.h"
using namespace state;

Iron::Iron()
{
    
}
Element* Iron::clone() const
{
    return new Iron(*this);
}
void Iron::beingattacked()
{
    this->life--;
}
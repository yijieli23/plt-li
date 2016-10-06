/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Sea.h"
using namespace state;

Sea::Sea()
{
    
}
Element* Sea::clone() const
{
    return new Sea(*this);
}

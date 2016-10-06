/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ElementFactory.h"

using namespace state;

ElementFactory::~ElementFactory()
{
    list.clear();
}

Element* const ElementFactory::newInstance(int id)
{
    return list[id]->newInstance();
}

void ElementFactory::registerType(int id, AElementAlloc* a)
{
    list[id]=a;
}
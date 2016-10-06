/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementAlloc.h"
using namespace state;

template<class E,typename ID>
    ElementAlloc<E,ID>::ElementAlloc(ID id):id(id){}

template<class E,typename ID>
Element* ElementAlloc<E,ID>::newInstance()
{
    return new E(id);
}
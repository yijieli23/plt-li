/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ListEvent.h"
#include "ElementList.h"

using namespace state;

ListEvent::ListEvent(const ElementList& list, int idx): list(list),idx(idx){}

StateEvent* ListEvent::clone() const
{
    return new ListEvent(*this);
}
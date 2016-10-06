/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StateEvent.h"

using namespace state;

StateEvent::StateEvent(const State& s, StateEventId id) : state(s),id(id){}

StateEvent::~StateEvent()
{}

StateEvent* StateEvent::clone() const
{
    return new StateEvent(*this);
}

bool StateEvent::operator ==(StateEventId id) const
{
    if(this->id==id)
        return true;
    return false;
}

bool StateEvent::operator !=(StateEventId id) const
{
    if(this->id!=id)
        return true;
    return false;
}
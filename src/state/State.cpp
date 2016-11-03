/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"
#include <fstream>
namespace state{

State::State(): chars(*this), grid(*this)
{
    epoch=0;
}

State::~State()
{
}

State* State::clone() const
{
    return new State(*this);
}

void State::copy(const State& other)
{
    setGrid(other.getGrid());
    setChars(other.getChars());
    setEpoch(other.getEpoch());
}

bool State::equals(const State& other) const
{
    return true;
}

int State::getEpoch() const
{
    return epoch;
}

ElementGrid& State::getGrid ()
{
    return grid;
}

const ElementGrid& State::getGrid() const
{
    return grid;
}

const ElementList& State::getChars () const
{
    return chars;
}

ElementList& State::getChars()
{
    return chars;
}

const MobileElement* State::getChar(int idx) const
{
    return (MobileElement*)(chars.get(idx));
}

MobileElement* State::getChar(int idx)
{
    return (MobileElement*)(chars.get(idx));
}

 
void State::setElementFactory(ElementFactory* f)
{
    chars.setElementFactory(f);
    grid.setElementFactory(f);
}

void State::setEpoch(int time)
{
    epoch=time;
}

void State::setGrid(const ElementGrid& eg)
{
    grid.copy(eg);
}

void State::setChars(const ElementList& el)
{
    chars.copy(el);
}

void State::loadLevel(const char* filename)
{
    grid.load(filename);
}

void State::loadChars(const char* filename)
{
//    chars.load(filename);
}

void State::notifyObservers(StateEventId id) const
{
    
}

void State::notifyObservers(const StateEvent& e) const
{
   
}
};
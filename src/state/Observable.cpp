/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Observable.h"

using namespace state;

Observable::~Observable()
{
    observers.clear();
}

void Observable::registerObserver(StateObserver* o) const
{
    observers.push_back(o);
}

void Observable::unregisterObserver(StateObserver* o) const
{
}

void Observable::notifyObservers(const StateEvent& e) const
{
}
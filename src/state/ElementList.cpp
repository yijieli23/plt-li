/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementList.h"
namespace state{

ElementList::ElementList(State& s):s(s){};

ElementList::~ElementList()
{
    elements.clear();
}

ElementList* ElementList::clone() const
{
    return new ElementList(*this);
}

void ElementList::copy(const ElementList& list)
{
    for(int i=0;i<list.size();i++)
        elements.push_back(list.get(i));
}

bool ElementList::equals(const ElementList& other) const
{
    for(size_t i=0;i<elements.size();i++)
        if(! elements[i]->equals(*other.get(i)))
            return false;
        //else
            return true;
}

const State& ElementList::getState() 
{
    return this->s;
}

int ElementList::size() const
{
    return elements.size();
}

Element* ElementList::get(int i) const
{
    return elements.at(i);
}

void ElementList::clear()
{
    elements.clear();
}

void ElementList::setElementFactory(ElementFactory* f)
{
    factory = f;
}

void ElementList::set(int i, Element* e)
{
    elements.at(i)=e;
}

void ElementList::notifyObservers(int i) const
{
//    ListEvent listEvent(*this, i);
//    Observable::notifyObservers(listEvent);
}
};
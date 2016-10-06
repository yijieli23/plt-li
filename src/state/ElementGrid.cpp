/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementGrid.h"

using namespace state;

ElementGrid::ElementGrid(State& s) : ElementList(s){}

ElementGrid* ElementGrid::clone() const
{
	return new ElementGrid(*this);
}

void ElementGrid::copy(const ElementGrid& other)
{
   
	for(int i=0;i<other.size();i++)
		elements.push_back(other.get(i)->clone());
}

bool ElementGrid::equals(const ElementGrid& other) const
{
	
	for(int i=0;i<elements.size();i++)
		if(! elements[i]->equals(*other.get(i))) return false;
		return false;
        
	return true;
}


int ElementGrid::getWidth() const
{
	return width;
}

int ElementGrid::getHeight() const
{
	return height;
}

void ElementGrid::setWidth(int w)
{
	width = w;
}

void ElementGrid::setHeight(int h)
{
	height = h;
}


Element * ElementGrid::getCell(int i, int j) const
{	
	for(Element* e : elements)
            if(e->getX() == i && e->getY() == j) return e;
}

void ElementGrid::setCell(int i, int j, Element * e)
{
	e->setX(i);
	e->setY(j);
	elements.push_back(e);
}

void ElementGrid::load(const char* file_name)
{
	
}

void ElementGrid::notifyObservers(int i, int j) const
{
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MoveCharacter.h"
#include "state/ElementList.h"
#include "state/State.h"

namespace engine{
    MoveCharacter::MoveCharacter(int idx): idx(idx)
    {
        
    }
    void MoveCharacter::setCoords(int dx, int dy)
    {
        this->dx = dx;
        this->dy = dy;
    }
    void MoveCharacter::setOrientation(state::Direction prev, state::Direction next)
    {
        prevOrientation = prev;
        newOrientation = next;
    }
    void MoveCharacter::setDirection(state::Direction prev, state::Direction next)
    {
        prevDirection=prev;
        newDirection=next;
    }
    void MoveCharacter::apply(state::State& s, bool notify)
    {
        int newPos;
	state::ElementList& list = s.getChars();
	state::MobileElement* d;
	state::MobileElement* e = (state::MobileElement*)list.get(idx);
	if(((e->getX()+dx)>=0) && ((e->getX()+dx)<10)) e->setX(e->getX()+dx);
	if(((e->getY()+dy)>=0) && ((e->getY()+dy)<15)) e->setY(e->getY()+dy);
	e->setOrientation(newOrientation);
	d = (state::MobileElement*)list.get(e->getY() + 15*e->getX());
	d->setX(s.getGrid().get(idx)->getX());
	d->setY(s.getGrid().get(idx)->getY());
	newPos = e->getY() + 15*e->getX();
	list.set(newPos,e);
	list.set(idx,d);
    }
    void MoveCharacter::undo(state::State& s, bool notify)
    {
        int prevPos;
	state::ElementList& list = s.getChars();
	state::MobileElement* d;
	state::MobileElement* e = (state::MobileElement*)list.get(idx);
	e->setX(e->getX()-dx);
	e->setY(e->getY()-dy);
	e->setOrientation(prevOrientation);
	d = (state::MobileElement*)list.get(e->getY() + 15*e->getX());
	d->setX(s.getGrid().get(idx)->getX());
	d->setY(s.getGrid().get(idx)->getY());
	prevPos = e->getY() + 15*e->getX();
	list.set(prevPos,e);
	list.set(idx,d);
    }
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AttackUnit.h"


namespace engine{
    AttackUnit::AttackUnit(int idx): idx(idx)
    {
        
    }
    void AttackUnit::setCoords(int dx, int dy)
    {
        this->dx=dx;
        this->dy=dy;
    }
    void AttackUnit::setOrientation(state::Direction prev, state::Direction next)
    {
        prevOrientation=prev;
        newOrientation=next;
    }
    void AttackUnit::setDirection(state::Direction prev, state::Direction next)
    {
        prevDirection=prev;
        newDirection=next;
    }
    void AttackUnit::setHp(int prev, int next)
    {
        prevHp=prev;
        newHp=next;
    }
    void AttackUnit::apply(state::State& s, bool notify)
    {
        std::cout<<"attack"<<std::endl;
        state::ElementList list= s.getChars();
        state::MobileElement *e= (state::MobileElement*)list.get(idx);
        int posEnemy= e->getY()+dy+15*(e->getX()+dx);
        state::MobileElement* d = (state::MobileElement*)list.get(posEnemy);
        
    }
    void AttackUnit::undo(state::State& s, bool notify)
    {
        
    }
};
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ruler.h"
#include "CommandSet.h"
#include "DirectionCommand.h"
#include <iostream>
#include "../state/MobileElement.h"



namespace engine{
    void Ruler::moveChar(int idx)
    {
        
    }
    void Ruler::resChar(int idx)
    {
        
    }
    Ruler::Ruler(ActionList& a, const state::State& s, const CommandSet& cs) : currentState(s), commands(cs),  actions(a)
    {
    }

    Ruler::~Ruler()
    {
    }

    void Ruler::collisions()
    {

    }

    void Ruler::apply()
    {
    }
};
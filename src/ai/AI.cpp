/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AI.h"
#include "state/State.h"
#include "../state/MobileElement.h"
namespace ai{
    bool AI::nextLocation(int idx, int x, int y) const
    {
        int nextx=x +mainState.getChar(idx)->getX();
        int nexty=y +mainState.getChar(idx)->getY();
        if((state::MobileElement*)mainState.getChar(nexty + 15*nextx)->getMobileTypeId())
            return true;
        return false;
    }
    AI::AI(const state::State& mainState) : mainState(mainState)
    {
        
    }
    AI::~AI()
    {
        
    }
}
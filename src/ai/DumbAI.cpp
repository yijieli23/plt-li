/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "DumbAI.h"
#include "engine/CommandSet.h"
#include "engine/DirectionCommand.h"
#include "state/State.h"
#include "engine/DirectionCommandEnemy.h"
#include <iostream>

namespace ai{
    
    DumbAI::DumbAI(const state::State& mainState) : AI(mainState)
    {
        srand (time(NULL));
    }
    
    
    void DumbAI::dumbMove(int idx, engine::CommandSet& commands)
    {
        int direction =rand()%4 + 1;
        std::cout<<idx<<":"<<direction<<std::endl;
 //       commands.set(new engine::DirectionCommandEnemy((state::Direction)direction));
    }
    
    
    void DumbAI::run(engine::CommandSet& commands)
    {
        for(int i=0;i<mainState.getChars().size();i++)
            dumbMove(i,commands);
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "DirectionCommandEnemy.h"
#include "state/Direction.h"
#include "render/Surface.h"
#include "state/State.h"
#include "../state/MobileTypeId.h"
#include "../state/EnemyTank.h"
#include <iostream>

using namespace state;

namespace engine{
    
    DirectionCommandEnemy::DirectionCommandEnemy(state::Direction id) : direction(id)
    {

    }
    CommandTypeId DirectionCommandEnemy::getTypeId() const
    {
 //       return id;
    }
    int DirectionCommandEnemy::getCharacter() const
    {
        return character;
    }
    state::Direction DirectionCommandEnemy::getDirection() const
    {
        return direction;
    }
    void DirectionCommandEnemy::run(State& state)
    {
        EnemyTank& enemy = state.getEnemyTank();
        auto& level = state.getLevel();
        switch(direction)
        {
            case(state::NONE):
                break;
                
            case(state::WEST):
                enemy.moveleft(level);
                break;
                
            case(state::EAST):
                enemy.moveright(level);
                break;
                
            case(state::NORTH):
                enemy.moveup(level);
                break;
                
            case(state::SOUTH):
                enemy.movedown(level);
                break;
        }
        std::cout<<"x"<<enemy.x<<" y"<<enemy.y<<std::endl;
   }
};

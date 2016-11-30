/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DirectionCommandBullet.h"
#include "state/Direction.h"
#include "render/Surface.h"
#include "state/State.h"
#include "../state/MobileTypeId.h"
#include "../state/JoueurTank.h"
#include "../state/Bullet.h"
#include <iostream>

using namespace state;

namespace engine{
    
    DirectionCommandBullet::DirectionCommandBullet(state::Direction id) : direction(id)
{

}
    
    void DirectionCommandBullet::run(State& state)
    {
        JoueurTank& joueur = state.getJoueurTank();
        auto& level = state.getLevel();
        switch(direction)
        {
            case(state::NONE):
                break;
                
            case(state::WEST):
                joueur.moveleft(level);
                break;
                
            case(state::EAST):
                joueur.moveright(level);
                break;
                
            case(state::NORTH):
                joueur.moveup(level);
                break;
                
            case(state::SOUTH):
                joueur.movedown(level);
                break;
        }
        std::cout<<"x"<<joueur.x<<" y"<<joueur.y<<std::endl;
   }
};
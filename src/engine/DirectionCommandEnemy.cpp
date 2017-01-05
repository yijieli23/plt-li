#include "DirectionCommandEnemy.h"
#include "state/Direction.h"
#include "render/Surface.h"
#include "state/State.h"
#include "../state/MobileTypeId.h"
#include "../state/EnemyTank.h"
#include <iostream>

using namespace state;

namespace engine{
    
    DirectionCommandEnemy::DirectionCommandEnemy(int i, state::Direction id) :num(i), direction(id)
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
        std::vector<EnemyTank>& enemys = state.getEnemyTank();
        auto& level = state.getLevel();
        
        
        switch(direction)
        {
            case(state::NONE):
                break;
                
            case(state::WEST):
                enemys[num].moveleft(level);
                break;
                
            case(state::EAST):
                enemys[num].moveright(level);
                break;
                
            case(state::NORTH):
                enemys[num].moveup(level);
                break;
                
            case(state::SOUTH):
                enemys[num].movedown(level);
                break;
        }
      //  std::cout<<"x"<<enemy.x<<" y"<<enemy.y<<std::endl;
   }
    
};

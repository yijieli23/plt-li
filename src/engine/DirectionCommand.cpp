/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DirectionCommand.h"
#include "state/Direction.h"
namespace engine{
    DirectionCommand::DirectionCommand(int c, state::Direction d): character(c), direction(d)
    {
//        id = DIRECTION;
    }
    CommandTypeId DirectionCommand::getTypeId() const
    {
 //       return id;
    }
    int DirectionCommand::getCharacter() const
    {
        return character;
    }
    state::Direction DirectionCommand::getDirection() const
    {
        return direction;
    }
};
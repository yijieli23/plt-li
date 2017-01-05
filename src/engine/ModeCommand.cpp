/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ModeCommand.h"
namespace engine{
    ModeCommand::ModeCommand(EngineMode mode): mode(mode)
    {
//        id = MODE;
    }
    CommandTypeId ModeCommand::getTypeId() const
    {
//        return id;
    }
    EngineMode ModeCommand::getMode() const
    {
        return mode;
    }
}
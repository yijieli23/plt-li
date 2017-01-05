/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "LoadCommand.h"
namespace engine{
    LoadCommand::LoadCommand(const char* f) : file_name(f)
    {
//        id = LOAD;
    }
    CommandTypeId LoadCommand::getTypeId() const
    {
//        return id;
    }
    const char* LoadCommand::getFileName() const
    {
        return file_name.c_str();
    }
};
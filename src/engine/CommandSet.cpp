/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CommandSet.h"
namespace engine{
    CommandSet::~CommandSet()
    {
        int i;
        for(i=0;i<commands.size();i++)
            delete commands[i];
        commands.clear();
    }
    int CommandSet::size() const
    {
        return commands.size();
    }
    Command* CommandSet::get(int category) const
    {
        return commands.at(category);
    }
    void CommandSet::set(Command* cmd)
    {
        commands.push_back(cmd);
    }
    void CommandSet::take(CommandSet& commands, bool replace)
    {
        
    }
    
    
};
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ActionList.h"
namespace engine{
    ActionList::ActionList(state::State& s, bool notify):s(s),notify(notify)
    {
        
    }
    ActionList::~ActionList()
    {
        
    }
    int ActionList::size() const
    {
        return actions.size();
    }
    Action* ActionList::get(int i) const
    {
        return actions[i];
    }
    void ActionList::apply()
    {
        int i;
        for(i=0;i<actions.size();i++)
            actions[i]->apply(s,notify);
    }
    void ActionList::undo()
    {
        int i;
        for(i=actions.size();i>=0;i--)
            actions[i]->undo(s,notify);
    }
    void ActionList::add(Action* action)
    {
        actions.push_back(action);
    }
}
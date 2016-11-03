/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Record.h"

namespace engine{
    Record::Record(state::State& s): mainState(s)
    {
        
    }
    Record::~Record()
    {
        
    }
    void Record::clear()
    {
        int i;
        for(i=0;i<actions.size();i++)
            delete actions[i];
        actions.clear();
    }
    void Record::startRecord()
    {
        int i;
        for(i=0;i<actions.size();i++)
        {
            
        }
    }
    void Record::recordOne(ActionList* list)
    {
        actions.push_back(list);
    }
    void Record::stopRecord()
    {
        
    }
    void Record::startReplay()
    {
        int i;
        initState=&mainState;
        state::State *newState;
        for(i=0;i<actions.size();i++)
        {
		actions[i]->apply();
		newState = new state::State;
		newState->copy(*initState);
		newState->setEpoch(mainState.getEpoch()+1);
		initState = newState;
		delete newState;
	}        
    }
    bool Record::replayOne()
    {
        
    }
    void Record::startRollback()
    {
        int i;
//	lastState = &mainState;
	state::State *prevState;
	for(i=actions.size();i>=0;i++)
	{
		actions[i]->undo();
		prevState = new state::State;
		prevState->copy(*lastState);
		prevState->setEpoch(mainState.getEpoch()-1);
		lastState = prevState;
		delete prevState;
	}
    }
    bool Record::rollbackOne()
    {
        
    }
};
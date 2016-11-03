/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
namespace engine{
    Engine::Engine()
//    Engine::Engine() : record(currentState)
{

}

Engine::~Engine()
{	
	delete currentCommands;
}

EngineMode Engine::getMode() const
{
	return mode;
}

const state::State& Engine::getState() const
{
	return currentState;
}

CommandSet* Engine::getCommandSet() const
{
	return currentCommands;
}

void Engine::addCommand(Command* cmd)
{
	currentCommands->set(cmd);
}

void Engine::takeCommands(CommandSet& commands)
{
	
}

std::mutex& Engine::getUpdateMutex () const
{
	return update_mutex;
}

void Engine::update()
{
	//~ swapCommands();
	ActionList* al;
	Ruler* ruler;
	//State newState;
	switch(mode)
	{
		case(PLAY):			
			//newState.copy(currentState);
			al = new ActionList(currentState,false);
			ruler = new Ruler(*al,currentState,*currentCommands);
			ruler->apply();
			ruler->collisions();
//			record.recordOne(al);
			delete ruler;
			delete al;
			break;
		case(RECORD):
//			record.startRecord();
			break;
		case(REPLAY):
//			record.startReplay();
			break;
		case(ROLLBACK):
//			record.startRollback();
			break;
		case(PAUSE):
//			record.stopRecord();
			break;
		case(CLOSE):
//			record.clear();
			break;
	}
}

void Engine::swapCommands ()
{
	CommandSet* tmp = currentCommands;
	currentCommands = waitingCommands;
	waitingCommands = tmp;
}

void Engine::setMode (EngineMode em)
{
	mode = em;
}

void Engine::loadLevel (const char* file_name)
{
	currentState.loadLevel(file_name);
}
}
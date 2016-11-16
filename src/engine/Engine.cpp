/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"
#include "../state/State.h"
using namespace state;
namespace engine{
    
    Engine::Engine() : record(currentState)
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
        
        for(size_t i=0;i<currentCommands->size();i++) {
            currentCommands->get(i)->run(currentState);
        }
        currentCommands->clear();
	
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
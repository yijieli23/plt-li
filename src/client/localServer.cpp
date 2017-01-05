#include "server.h"
#include <iostream>
#include <mutex>
using namespace server;

LocalServer::LocalServer(){

	
}
LocalServer::~LocalServer(){
}
void LocalServer::run(){

	while(!quit)
	{
		if(levelState.getTurnToPlay() == state::JOUEUR) {
			if (iaAutoMode) {
				ais->run(engine, *this);
				//dumbAI.run(engine);
			}
		}
		else if (levelState.getTurnToPlay() == state::NORMAL) {
			ais->run(engine, *this);
		}

		engine.update();
	}
	
}

void LocalServer::addCommand(engine::Command *cmd) {
	commandSet->set(cmd);
}



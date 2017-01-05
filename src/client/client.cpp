#include "client.h"
#include <iostream>
#include "../render/Surface.h"
#include "../engine/Engine.h"
#include "server.h"
#include "render/TileSetChars.h"

//~ #include <X11/Xlib.h>

using namespace client;

Client::Client(server::Server& serv) :serv(serv), engine(serv.getEngine()), levelState(serv.getLevelState()){
	
	this->tileSets.push_back(new render::TileSet()); 				  
	this->tileSets.push_back(new render::TileSetChars);

}
void Client::setTileSet(render::SceneLayer sceneLayer, const render::TileSet* tileSet){
	
	this->tileSets[sceneLayer] = tileSet;
}
void Client::init(){
    std::cout << "Enregistrement Observer" << std::endl;
    serv.registerObserver(this); 
}
void Client::run(){
	
	Client::init();
	this->init();

	while(acquireControls()){
		serv.getEngine().getUpdateMutex().lock();
		updateDisplay();
		serv.getEngine().getUpdateMutex().unlock();
	}
	serv.join();
}
void Client::serverChanged(const server::ServerEvent& e){
	
	if(e == server::STATE_CHANGED){
		
	}
	else if(e == server::INVALID){
		
	}	
}

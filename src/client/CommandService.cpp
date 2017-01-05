/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "server.h"
#include <iostream>
using namespace server;

CommandService::CommandService (CommandDB& commandDB) : AbstractService("/command"), commandDB(commandDB) {
    
}
HttpStatus CommandService::get (Json::Value& out, int id) const {
    const engine::Command* command = commandDB.getCommand();
    if (!command)
        throw ServiceException(HttpStatus::NOT_FOUND,"No command");
    
    out["type"] = command->getTypeId();
    
    switch(command->getTypeId()){
		case engine::CommandTypeId::MODE :
			out["mode"] = ((engine::ModeCommand*)command)->getMode();
		break;
		case engine::CommandTypeId::MOVE :
			out["x"] = ((engine::MoveCommand*)command)->getPositionX();
			out["y"] = ((engine::MoveCommand*)command)->getPositionY();
		break;
	}
    return HttpStatus::OK;
}

HttpStatus CommandService::put (Json::Value& out,const Json::Value& in) {
    
    int type = in["type"].asInt();
    
    if(type == 1){
		string file_name = in["file_name"].asString();
		commandDB.setCommand(std::move(make_unique<engine::LoadCommand>(file_name.c_str())));
	}
	else if (type == 2){
		int mode = in["mode"].asInt();
		commandDB.setCommand(std::move(make_unique<engine::ModeCommand>(static_cast<engine::EngineMode>(mode))));
	}

    return HttpStatus::CREATED;
}
HttpStatus CommandService::post (const Json::Value& in, int id) {
	
    if(in.isMember("type")){
		int type = in["type"].asInt();
		
		if(type == 1){
			string file_name = in["file_name"].asString();
			commandDB.setCommand(std::move(make_unique<engine::LoadCommand>(file_name.c_str())));
		}
		else if (type == 2){
			int mode = in["mode"].asInt();
			commandDB.setCommand(std::move(make_unique<engine::ModeCommand>(static_cast<engine::EngineMode>(mode))));
		}

	return HttpStatus::NO_CONTENT;
	
}
}
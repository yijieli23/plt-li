/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DirectionCommand.h"
#include "state/Direction.h"
#include "render/Surface.h"
#include "../state/MobileTypeId.h"
#include "../state/JoueurTank.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
namespace engine{
    state::JoueurTank joueur(14,4);
    
    DirectionCommand::DirectionCommand()
{
	//id = DIRECTION;
}
    CommandTypeId DirectionCommand::getTypeId() const
    {
 //       return id;
    }
    int DirectionCommand::getCharacter() const
    {
        return character;
    }
    state::Direction DirectionCommand::getDirection() const
    {
        return direction;
    }
    void DirectionCommand::move(int level[15][15])
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
           {
                
                joueur.moveleft(level);
                
                std::cout<<"leftbutton"<<std::endl;
                
           }
            
            
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
           {
               joueur.moveright(level);
                
               std::cout<<"rightbutton"<<std::endl;
               
           }
            
            
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
           {
               joueur.moveup(level);
                
               std::cout<<"upbutton"<<std::endl;
               
           }
            
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
           {
               joueur.movedown(level);
                
               std::cout<<"downbutton"<<std::endl;
                   
           }
    }
};
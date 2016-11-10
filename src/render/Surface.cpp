/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Surface.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "SFMLSurface.h"
#include "../state/MobileTypeId.h"
#include "../state/JoueurTank.h"
#include <time.h>
#include <unistd.h>
#include <ctime>
#include "../engine/DirectionCommand.h"
namespace render{
//     int level[270];
//     state::JoueurTank joueur;
     engine::DirectionCommand movecommand;
     render::SFMLSurface map1;
     
     int level[15][15]=
    {
    {21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21},
    {21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 21 , 16 , 21},
    {21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 21 , 16 , 21},
    {21 , 16 , 21 , 21 , 16 , 21 , 16 , 41 , 16 , 21 , 16 , 140, 21 , 16 , 21 },
    {21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 110, 16 , 21 },
    {110, 16 , 21 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 21 , 16 , 21 },
    {21 , 21 , 21 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 21 , 21 , 21 },
    {45 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 45 },
    {21 , 21 , 21 , 21 , 140, 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 },
    {21 , 21 , 21 , 21 , 21 , 21 , 16 , 18 , 16 , 21 , 21 , 21 , 21 , 21 , 21 },
    {21 , 41 , 41 , 21 , 21 , 21 , 16 , 21 , 16 , 21 , 21 , 21 , 21 , 41 , 41 },
    {21 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 21 },
    {21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 },
    {21 , 41 , 21 , 21 , 21 , 21 , 17 , 18 , 19 , 21 , 21 , 21 , 21 , 41 , 41 },
    {21 , 21 , 21 , 21 , 0  , 21 , 17 , 69 , 19 , 21 , 21 , 21 , 21 , 21 , 21 }
    };
    Surface::Surface()
    {

    }
    Surface::~Surface()
    {
        
    }
    void Surface::update()
    {
        
        if (!map1.load("../res/Battle City.png", sf::Vector2u(16, 16),(int*) level, 15, 15))
        {
            std::cerr<<"wrong"<<std::endl;
        }
    }
   
    int Surface::afficher()
    {
        sf::RenderWindow window(sf::VideoMode(272, 240), "Battle");
        window.setPosition(sf::Vector2i(100, 100));
        window.setSize(sf::Vector2u(640, 480));     
//        int *level=(int*) level1;
       
        update();
 
        while (window.isOpen())
        {
           movecommand.move(level);
           
           update();
            
           sf::Event event;
           while (window.pollEvent(event))
           {
               if(event.type == sf::Event::Closed)
                   window.close();
           }
           window.clear();
           window.draw(map1);
           window.display();
           
        }
        return 0;
    }
   
};
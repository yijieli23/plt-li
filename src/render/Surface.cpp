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

namespace render{
      
   Surface::Surface()
    {
        sf::RenderWindow window(sf::VideoMode(272, 240), "Battle");
        window.setPosition(sf::Vector2i(100, 100));
        window.setSize(sf::Vector2u(640, 480));
        sf::Clock clock;
         int level[] =
        {
//       01 , 02 , 03 , 04 , 05 , 06 , 07 , 08 , 09 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18
         0 ,  21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 23 , 24 , 21 ,
         21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 21 , 16 , 21 , 23 , 24 , 21 ,
         21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 21 , 16 , 21 , 23 , 24 , 21 ,
         21 , 16 , 21 , 21 , 16 , 21 , 16 , 41 , 16 , 21 , 16 , 140, 21 , 16 , 21 , 48 , 49 , 21 ,
         21 , 16 , 21 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 16 , 21 , 110, 16 , 21 , 73 , 74 , 21 ,
         110, 16 , 21 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 21 , 16 , 21 , 98 , 99 , 21 ,
         21 , 21 , 21 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 21 , 21 , 21 , 148, 149, 21 ,
         45 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 45 , 173, 174, 21 ,
         21 , 21 , 21 , 21 , 140, 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 198, 199, 21 ,
         21 , 21 , 21 , 21 , 21 , 21 , 16 , 18 , 16 , 21 , 21 , 21 , 21 , 21 , 21 , 23 , 24 , 21 ,
         21 , 41 , 41 , 21 , 21 , 21 , 16 , 21 , 16 , 21 , 21 , 21 , 21 , 41 , 41 , 23 , 24 , 21 ,
         21 , 21 , 21 , 21 , 21 , 21 , 16 , 21 , 16 , 21 , 21 , 21 , 21 , 21 , 21 , 298, 299, 21 ,
         21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 323, 324, 21 ,
         41 , 41 , 21 , 21 , 21 , 21 , 17 , 18 , 19 , 21 , 21 , 21 , 21 , 41 , 41 , 348, 349, 21 ,
         21 , 21 , 21 , 21 , 21 , 21 , 17 , 69 , 19 , 21 , 21 , 21 , 21 , 21 , 21 , 23 , 24 , 21 ,

        }; 
        render::SFMLSurface map1;
        if (!map1.load("../res/Battle City.png", sf::Vector2u(16, 16), level, 18, 16))
        {
            std::cout<<"wrong"<<std::endl;
        }
        
//        state::JoueurTank joueur(state::JOUEUR);
        
        sf::Texture tex;
        if(!tex.loadFromFile("../res/joueur1.png"))
        {
            std::cout<<"wrong"<<std::endl;
        }
        sf::Sprite jou;
        jou.setTexture(tex);
        
   //     engine::DirectionCommand dcommand;
        while (window.isOpen())
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
           {
               std::cout<<"left"<<std::endl;
               

           }
   /*        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
           {
               std::cout<<"right"<<std::endl;
               jou.setRotation(90);
               jou.move(joueur.speed,0);
           }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
           {
               std::cout<<"up"<<std::endl;
               jou.setRotation(360);
               jou.move(0,-joueur.speed);
           }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
           {
               std::cout<<"down"<<std::endl;
               jou.setRotation(180);
               jou.move(0,joueur.speed);
           }
            */
          //  dcommand.DirectionJoueur(jou);
            
           sf::Event event;
           while (window.pollEvent(event))
           {
               if(event.type == sf::Event::Closed)
                   window.close();
           }
           
           
           

           window.clear();
           window.draw(map1);
//           window.draw(jou);
           window.display();
           
        }

    
}
    Surface::~Surface()
    {
        
    }
    
};
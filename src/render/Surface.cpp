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
#include "../state/EnemyTank.h"
#include <vector>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include "../engine/DirectionCommand.h"
#include "engine/Engine.h"
using namespace std;
namespace render {
    
    render::SFMLSurface map1;



    
//    engine::DirectionCommand movecommand(state::NONE, level);
    engine::Engine engine1;
    state::State state1;

    Surface::Surface() {

    }

    Surface::~Surface() {

    }

    void Surface::update() {

        if (!map1.load("res/Battle City.png", sf::Vector2u(16, 16), state1.getLevel(), 15, 15)) {
            std::cerr << "wrong" << std::endl;
        }
    }

    int Surface::afficher() {
        sf::RenderWindow window(sf::VideoMode(240, 240), "Battle");
        window.setPosition(sf::Vector2i(400, 100));
        window.setSize(sf::Vector2u(576, 480));


        //        int *level=(int*) level1;
                    

        
        update();
        
        while (window.isOpen()) {
            

            //   movecommand.move(level);
            //   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
               

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        std::cout << "left" << std::endl;
                        engine1.addCommand(new engine::DirectionCommand(state::WEST));
                    }
                    else if (event.key.code == sf::Keyboard::Right)
                        engine1.addCommand(new engine::DirectionCommand(state::EAST));


                    else if (event.key.code == sf::Keyboard::Up)
                        engine1.addCommand(new engine::DirectionCommand(state::NORTH));

                    else if (event.key.code == sf::Keyboard::Down)
                        engine1.addCommand(new engine::DirectionCommand(state::SOUTH));
                }

            }
            //       engine.add(new DirectionCommand(rand()%4));
           
            engine1.update();
            
            window.clear();
            window.draw(map1);
            window.display();

        }
        return 0;
    }

};
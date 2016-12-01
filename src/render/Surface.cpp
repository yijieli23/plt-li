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
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include "../engine/DirectionCommand.h"
#include "engine/Engine.h"
#include "../ai/DumbAI.h"
#include "engine/DirectionCommandEnemy.h"
#include <cstdlib>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
 


using namespace std;
namespace render {
    


engine::Engine engine1;

//    engine::DirectionCommand movecommand(state::NONE, level);

    Surface::Surface() {

    }

    Surface::~Surface() {

    }
    
    void Surface::multith(int n)
    {
       
            engine1.addCommand(new engine::DirectionCommandEnemy(n,state::Direction(rand()%4+1)));

    }
    

    int Surface::afficher() {
    
   
   
        sf::RenderWindow window(sf::VideoMode(240, 240), "Battle");
        window.setPosition(sf::Vector2i(400, 100));
        window.setSize(sf::Vector2u(576, 480));
        

        //        int *level=(int*) level1;
    
    
    
        const state::State& state1 = engine1.getState();
        ai::DumbAI ai1(state1);
    engine::DirectionCommand direction1(state::NONE);
        
        render::SFMLSurface map1;
    if (!map1.load("res/Battle City.png", sf::Vector2u(16, 16), state1.getLevel(), 15, 15)) {
            std::cerr << "wrong" << std::endl;
        }
 
  
        while (window.isOpen()) {
            
            //   movecommand.move(level);
            //   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            
            sf::Event event;
            while (window.pollEvent(event)) {
            switch(event.type)
            {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed :
                    {
                        
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Left:
                        std::cout << "left" << std::endl;
                        engine1.addCommand(new engine::DirectionCommand(state::WEST));
                        break;
                    
                        case sf::Keyboard::Right:
                        std::cout << "right" << std::endl;
                        engine1.addCommand(new engine::DirectionCommand(state::EAST));
                        break;
                        
                        case sf::Keyboard::Up:
                        std::cout << "up" << std::endl;
                        engine1.addCommand(new engine::DirectionCommand(state::NORTH));
                        break;
                        
                        case sf::Keyboard::Down:
                        std::cout << "down" << std::endl;
                        engine1.addCommand(new engine::DirectionCommand(state::SOUTH));
                        break;
                        
                        case sf::Keyboard::F:
                            
                        default:
                            break;
                    }
                    
                    for(int i=0;i<3;i++)
                    {
                        std::thread t(&Surface::multith, this, i);
                        t.join();
                    }
                    
                    }
                default:
                    break;    
            }
                
    
        }
            engine1.update();
        
            if (!map1.load("res/Battle City.png", sf::Vector2u(16, 16), state1.getLevel(), 15, 15)) 
            {
                std::cerr << "wrong" << std::endl;
            }
            
            window.clear();
            window.draw(map1);
            window.display();
            
        }
        return 0;
    
}

};

 
                       
                       
                //    engine1.addCommand(new engine::DirectionCommandEnemy(0,state::Direction(rand()%4+1)));
                //    engine1.addCommand(new engine::DirectionCommandEnemy(1,state::Direction(rand()%4+1)));
                //    engine1.addCommand(new engine::DirectionCommandEnemy(2,state::Direction(rand()%4+1)));
                    /*
                    if(flag%3==0)
                    {
                        engine1.addCommand(new engine::DirectionCommandEnemy(0,state::SOUTH));
                        engine1.addCommand(new engine::DirectionCommandEnemy(1,state::SOUTH));
                        engine1.addCommand(new engine::DirectionCommandEnemy(2,state::SOUTH));
                        
                    }
                    else
                    {
                        engine1.addCommand(new engine::DirectionCommandEnemy(0,state::Direction(rand()%4+1)));
                        engine1.addCommand(new engine::DirectionCommandEnemy(1,state::Direction(rand()%4+1)));
                        engine1.addCommand(new engine::DirectionCommandEnemy(2,state::Direction(rand()%4+1)));
                        
                        
                    }
                    */
#include <iostream>

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "render.h"
#include "state.h"
#include "render/SFMLSurface.h"


void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace state;





int main()
{
    sf::RenderWindow window(sf::VideoMode(272, 240), "Battle City");
    const int level[] =
    {
//       01 , 02 , 03 , 04 , 05 , 06 , 07 , 08 , 09 , 10 , 11 , 12 , 13 , 14 , 15 , 16 ,
         110, 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 21 , 23 , 24 , 21 ,
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

    render::SFMLSurface map;
    if (!map.load("../res/Battle City.png", sf::Vector2u(16, 16), level, 18, 16))
        return -1;
    sf::Texture tex1;
    if(!tex1.loadFromFile("../res/joueur1.png"))
    {
        
    }
    
    sf::Sprite jou;
    jou.setTexture(tex1);
    
    window.setPosition(sf::Vector2i(100, 100));
    window.setSize(sf::Vector2u(640, 480));

    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            jou.setRotation(270);
            jou.move(-0.1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            jou.setRotation(90);
            jou.move(0.1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            jou.setRotation(360);
            jou.move(0,-0.1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            jou.setRotation(180);
            jou.move(0,0.1);
        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(map);
        window.draw(jou);
        window.display();
    }

    return 0;
}


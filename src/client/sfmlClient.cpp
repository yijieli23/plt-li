#include "client.h"
#include <iostream>
#include <fstream>

#include "state.h"


#include "../ai/AI.h"
#include "server.h"


using namespace client;

SFMLClient::SFMLClient(server::Server& serv) : Client(serv), window(sf::VideoMode(1024, 512), "battle city") {

	this->surfaces.push_back(new render::SFMLSurface());	//GRID_LAYER
	this->surfaces.push_back(new render::SFMLSurface());	//BUILDS_LAYER
	this->surfaces.push_back(new render::SFMLSurface());	//CHARACTERS_LAYER
}
void SFMLClient::init(){


	text.setFont(font);
	text.setString("game start");
	text.setCharacterSize(15);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);

	
	
	
	//FACTORY
	state::ElementFactory* factory = new state::ElementFactory();


	factory->registerType('1', new state::ElementAlloc <state::StaticElement, state::StaticElementTypeId>(state::WOOD));
	factory->registerType('2', new state::ElementAlloc <state::StaticElement, state::StaticElementTypeId>(state::IRON));
	factory->registerType('3', new state::ElementAlloc <state::StaticElement, state::StaticElementTypeId>(state::SEA));
	factory->registerType('H', new state::ElementAlloc <state::MobileElement, state::MobileTypeId>(state::JOUEUR));
	factory->registerType('M', new state::ElementAlloc <state::MobileElement, state::MobileTypeId>(state::NORMAL));
	/*********************************/
	
	levelState.setElementFactory(factory);
	

	
	render::ElementListLayer* layerGrid = new render::ElementListLayer();
	layerGrid->setSurface(this->surfaces[render::GRID_LAYER]);
	
	layerGrid->setTileSet(this->tileSets[render::GRID_LAYER]);
	
	scene.setLayer(render::GRID_LAYER, layerGrid);

	state::ElementList& characters = levelState.getElementList();
	
	state::Element* JoueurTank = factory->newInstance('H');	
	JoueurTank->setX(14);
	JoueurTank->setY(4);
	
	state::Element* EnemyTank = factory->newInstance('M');	
	EnemyTank->setX(0);
	EnemyTank->setY(0);
        
	state::Element* EnemyTank = factory->newInstance('M');	
	EnemyTank->setX(0);
	EnemyTank->setY(7);
        
        state::Element* EnemyTank = factory->newInstance('M');	
	EnemyTank->setX(0);
	EnemyTank->setY(14);

	

	render::ElementListLayer* layerCharacters = new render::ElementListLayer();
	layerCharacters->setSurface(this->surfaces[render::CHARACTERS_LAYER]);
	layerCharacters->setTileSet(this->tileSets[render::CHARACTERS_LAYER]);
	
	scene.setLayer(render::CHARACTERS_LAYER, layerCharacters);

	


	render::Layer* layerBar = new render::Layer();

	layerBar->setSurface(this->surfaces[render::GRID_LAYER]);
	
	layerBar->setTileSet(this->tileSets[render::GRID_LAYER]);

	
	state::ElementGrid& elementGrid = levelState.getElementGrid();
	elementGrid.registerObserver(layerGrid);
	elementGrid.notifyObservers(-1,-1);
		
	state::ElementList& charactersList = levelState.getElementList();
	charactersList.registerObserver(layerCharacters);
	
	charactersList.notifyObservers(-1);

	
	moveRange.registerObserver(layerMoveRange);
	
	
}
bool SFMLClient::acquireControls() {

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
	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){
	this->window.clear();
	this->window.draw(*((render::SFMLSurface*)surfaces[render::GRID_LAYER]));
	this->window.draw(*((render::SFMLSurface*)surfaces[render::BUILDS_LAYER]));
	this->window.draw(*((render::SFMLSurface*)surfaces[render::CHARACTERS_LAYER]));
	this->window.display();
}








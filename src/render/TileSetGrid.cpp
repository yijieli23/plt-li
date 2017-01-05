/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TileSetGrid.h"

namespace render{
    TileSetGrid::TileSetGrid() : file_name("res/Battle city.png"), cellWidth(16), cellHeight(16)
{
	tiles.push_back(new StaticTile(16,112)); //GROUND
	tiles.push_back(new StaticTile(128,112)); //SEA
	tiles.push_back(new StaticTile(48,96)); //MOUNTAIN
	tiles.push_back(new StaticTile(224,112)); //FOREST
}

int TileSetGrid::getCellWidth() const{ return cellWidth; }

int TileSetGrid::getCellHeight() const{ return cellHeight; }

const char* TileSetGrid::getImageFile() const{ return file_name; }

/*const Tile* TileSetGrid::getElementTile(const state::Element* e) const
{
	if(e->isStatic())
	{
		switch(((StaticElement*)e)->getStaticTypeId())
		{
			case(PLAIN):
				return tiles[PLAIN];
			case(SEA):
				return tiles[SEA];
			case(MOUNTAIN):
				return tiles[MOUNTAIN];
			case(FOREST):
				return tiles[FOREST];
		}
	}
	throw std::runtime_error("problem with TileSetGrid::getElementTile");
 
}*/
};
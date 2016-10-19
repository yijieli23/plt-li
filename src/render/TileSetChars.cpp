/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TileSetChars.h"


namespace render{
    TileSetChars::TileSetChars() : file_name("../res/Battle City.png"), cellWidth(16), cellHeight(16)
{
	tiles.push_back(new StaticTile(304,0)); 
	tiles.push_back(new StaticTile(16,0)); 
	tiles.push_back(new StaticTile(32,0)); 
	tiles.push_back(new StaticTile(16,16));
}

int TileSetChars::getCellWidth() const{ return cellWidth; }

int TileSetChars::getCellHeight() const{ return cellHeight; }

const char* TileSetChars::getImageFile() const{ return file_name; }

/*const Tile* TileSetChars::getElementTile(const Element* e) const
{
	if(!(e->isStatic()))
	{
		switch((MobileElement* e)->getMobileTypeId())
		{
			case(JOUEUR):
				return tiles[JOUEUR];
			case(NORMAL):
				return tiles[NORMAL];
			case(QUICK):
				return tiles[QUICK];
			
		}
	}
 
}*/
};
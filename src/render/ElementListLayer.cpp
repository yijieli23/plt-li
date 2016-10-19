/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementListLayer.h"
#include "../state/ElementList.h"
namespace render{
    void ElementListLayer::update(const state::ElementList& list, int i)
{
	int cellWidth = tileset->getCellWidth();
	int cellHeight = tileset->getCellHeight();
	int j;
	surface->loadTexture(tileset->getImageFile());
	surface->setSpriteCount(list.size());
	state::Element* e;
	if(i==-1)
	{
		for(j = 0; j < list.size(); j++)
		{
			e = list.get(j);
			const Tile* tile = tileset->getElementTile(e);
			surface->setSpriteTexture(j, (StaticTile*)tile);
			surface->setSpriteLocation(j, e->getY()*cellWidth, e->getX()*cellHeight);
		}
	}
	else if (i<-1){
		for(j = 0; j < list.size(); j++)
		{
			e = list.get(j);
			const Tile* tile = tileset->getElementTile(e);
			surface->setSpriteTexture(j, (StaticTile*)tile);
			surface->setSpriteLocation(j, e->getY()*cellWidth, e->getX()*cellHeight);
		}
	}		
	else if(i>=0)
	{
		e = list.get(i);	
		const Tile* tile = tileset->getElementTile(e);
		surface->setSpriteTexture(i, (StaticTile*)tile);
		surface->setSpriteLocation(i, e->getY()*cellWidth, e->getX()*cellHeight);
	}
}

void ElementListLayer::stateChanged(const state::StateEvent& e)
{
	
}
};
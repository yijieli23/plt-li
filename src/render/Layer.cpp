/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"

namespace render{
    
Layer::Layer()
{
}

Layer::~Layer()
{
}
		
const TileSet* Layer::getTileSet() const
{
	return tileset;
}

void Layer::setTileSet(const TileSet* tileset)
{
	this->tileset=tileset;
}

void Layer::setSurface(Surface* surface)
{
	this->surface=surface;
}

void Layer::setAnimation (int i, Animation* a)
{
	std::map<int,Animation*>::iterator it = animations.begin();
	animations.insert (it, std::pair<int,Animation*>(i,a));
}

void Layer::stateChanged(const state::StateEvent& e)
{
}
}
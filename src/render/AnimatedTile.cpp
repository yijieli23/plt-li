/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "AnimatedTile.h"
namespace render{
    AnimatedTile::AnimatedTile(float rate) : rate(rate)
    {
    }
    AnimatedTile::~AnimatedTile()
    {
        
    }
    bool AnimatedTile::isAnimated()const
    {
        return true;
    }
    
    float AnimatedTile::getRate() const
    {
        return rate;
    }
    
    int AnimatedTile::getTileCount() const
    {
        return tiles.size();
    }
    const Tile* AnimatedTile::getTile(int i) const
    {
        return tiles.at(i);
    }
    const Tile* AnimatedTile::getTile(int64_t time) const
    {
        
    }
    void AnimatedTile::setRate(float rate)
    {
        this->rate = rate;
    }
    void AnimatedTile::addTile(Tile* tile)
    {
        tiles.push_back(tile);
    }
    void AnimatedTile::setTile(int i, Tile* tile)
    {
        tiles[i]=tile;
    }
};
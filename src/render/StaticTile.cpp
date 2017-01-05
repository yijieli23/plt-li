/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StaticTile.h"
namespace render{
    
StaticTile::StaticTile(int x,int y) : x(x), y(y), width(16), height(16)
{
}

bool StaticTile::isAnimated() const{ return false; }
		
int StaticTile::getX() const{return x;}

int StaticTile::getY() const{return y;}

int StaticTile::getHeight() const{return height;}

int StaticTile::getWidth() const{return width;}

void StaticTile::setX(int x){this->x=x;}

void StaticTile::setY(int y){this->y=y;}

void StaticTile::setWidth(int w){width=w;}

void StaticTile::setHeight(int h){height=h;}
    
};
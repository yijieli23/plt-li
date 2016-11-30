/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Bullet.h"
#include <iostream>
#include "JoueurTank.h"
#include "EnemyTank.h"
namespace state{
    Bullet::Bullet(){
        
    }
Element* Bullet::clone() const
{
    return new Bullet(*this);
}
void Bullet::gene(MobileTypeId type, Direction d){
    switch(type)
        {
            case JOUEUR:
            {
                switch(d)
                {
                case NORTH:
                    this->orientation=NORTH;
                    this->x=joueur.x-1;
                    this->y=joueur.y;
                break;
                case WEST:
                    this->orientation=WEST;
                    this->x=joueur.x;
                    this->y=joueur.y-1;
                break;
                case SOUTH:
                    this->orientation=SOUTH;
                    this->x=joueur.x+1;
                    this->y=joueur.y;
                break;
                case EAST:
                    this->orientation=EAST;
                    this->x=joueur.x;
                    this->y=joueur.y+1;
                break;
                }
            }
            case NORMAL:
            {
                switch(d)
                {
                case NORTH:
                    this->orientation=NORTH;
                    this->x=et.x-1;
                    this->y=et.y;
                break;
                case WEST:
                    this->orientation=WEST;
                    this->x=et.x;
                    this->y=et.y-1;
                break;
                case SOUTH:
                    this->orientation=SOUTH;
                    this->x=et.x+1;
                    this->y=et.y;
                break;
                case EAST:
                    this->orientation=EAST;
                    this->x=et.x;
                    this->y=et.y+1;
                break;
                }
            }
        }
}
void Bullet::init(std::vector<int>& level, Direction d)
{
    switch(d)
    {
            case NORTH:
                level[this->x*15+this->y]=93;
                break;
            case WEST:
                level[this->x*15+this->y]=94;
                break;
            case SOUTH:
                level[this->x*15+this->y]=95;
                break;
            case EAST:
                level[this->x*15+this->y]=96;
                break;
    }  
}
void Bullet::movedown(std::vector<int>& level)
{
    while(level[(this->x+1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x+1;
        level[this->x*15+this->y]=4;
    }
}
void Bullet::moveleft(std::vector<int>& level)
{
    while(level[this->x*15+this->y-1]==21)
        {
            level[this->x*15+this->y]=21;
            this->y=this->y-1;
            level[this->x*15+this->y]=2;
        }
}
void Bullet::moveright(std::vector<int>& level)
{

        while((level[this->x*15+this->y+1]==21)&&(this->y+1<=14))
        {
            level[this->x*15+this->y]=21;
            this->y=this->y+1;
            level[this->x*15+this->y]=6;
        }
}
void Bullet::moveup(std::vector<int>& level)
{
    while(level[(this->x-1)*15+this->y]==21)
    {
        level[this->x*15+this->y]=21;
        this->x=this->x-1;
        level[this->x*15+this->y]=0;
    }
}
    
};
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Animation.h"

namespace render{
    Animation::Animation (int i, int x, int y, const Tile* a): i(i), x(x), y(y), tile(a)
    {
        
    }
    void Animation::setDirection(state::Direction d)
    {
        direction=d;
    }
    void Animation::setSpeed(float speed)
    {
        this->speed = speed;
    }
    void Animation::update(int64_t time, Surface* surface)
    {
        
    }
};

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ruler.h"

namespace engine{
    void Ruler::moveChar(int idx)
    {
        
    }
    void Ruler::resChar(int idx)
    {
        
    }
    Ruler::Ruler(ActionList& a, const state::State& s, const CommandSet& cs) : actions(a), currentState(s), commands(cs)
    {
    }

    Ruler::~Ruler()
    {
    }

    void Ruler::collisions()
    {

    }

    void Ruler::apply()
    {
            int i,idx;	
            Action* action;
            state::MobileElement* me;
            for(i=0;i<commands.size();i++)
            {
                    idx = ((DirectionCommand*)commands.get(i))->getCharacter();
                    me = (state::MobileElement*)currentState.getChar(idx);		
                    switch(commands.get(i)->getTypeId())
                    {
                            case(LOAD):

                                    break;
                            case(MODE):

                                    break;
                            case(DIRECTION):
                                    switch(((DirectionCommand*)commands.get(i))->getDirection())
                                    {
                                        case(state::NORTH):
                                                    std::cout << "posN " << (((state::MobileElement*)currentState.getChar(me->getY()+15*(me->getX()-1)))->getMobileTypeId()) << ":" << me->getY()+15*(me->getX()-1) << std::endl;
                                                    //~ if(((MobileElement*)currentState.getChar(me->getY()+15*(me->getX()-1)))->getMobileTypeId() == EMPTY)
                                                    {
                                                            action =new MoveCharacter(idx);
                                                            ((MoveCharacter*)action)->setCoords(-1,0);
                                                            ((MoveCharacter*)action)->setOrientation(me->getOrientation(),state::NORTH);
                                                            ((MoveCharacter*)action)->setDirection(me->getDirection(),state::NORTH);
                                                    }
                                                    //~ else
                                                    //~ {
                                                            //~ action = new AttackUnit(idx);
                                                            //~ ((AttackUnit*)action)->setCoords(-1,0);
                                                            //~ ((AttackUnit*)action)->setOrientation(me->getOrientation(),NORTH);
                                                            //~ ((AttackUnit*)action)->setDirection(me->getDirection(),NORTH);
                                                    //~ }
                                                    break;
                                        case(state::EAST):
                                                    std::cout << "posE " << (((state::MobileElement*)currentState.getChar(me->getY()+1+15*(me->getX())))->getMobileTypeId()) << ":" << me->getY()+1+15*(me->getX()) << std::endl;
                                                    //~ if(((MobileElement*)currentState.getChar(me->getY()+1+15*(me->getX())))->getMobileTypeId() == EMPTY)
                                                    {
                                                            action = new MoveCharacter(idx);
                                                            ((MoveCharacter*)action)->setCoords(0,1);						
                                                            ((MoveCharacter*)action)->setOrientation(me->getOrientation(),state::EAST);
                                                            ((MoveCharacter*)action)->setDirection(me->getDirection(),state::EAST);
                                                    }
                                                    //~ else
                                                    //~ {
                                                            //~ action = new AttackUnit(idx);
                                                            //~ ((AttackUnit*)action)->setCoords(0,1);						
                                                            //~ ((AttackUnit*)action)->setOrientation(me->getOrientation(),EAST);
                                                            //~ ((AttackUnit*)action)->setDirection(me->getDirection(),EAST);
                                                    //~ }
                                                    break;
                                        case(state::WEST):
                                                    std::cout << "posW " << (((state::MobileElement*)currentState.getChar(me->getY()-1+15*(me->getX())))->getMobileTypeId()) << ":" <<  me->getY()-1+15*(me->getX()) << std::endl;
                                                    //~ if(((MobileElement*)currentState.getChar(me->getY()-1+15*(me->getX())))->getMobileTypeId() == EMPTY)
                                                    {
                                                            action = new MoveCharacter(idx);
                                                            ((MoveCharacter*)action)->setCoords(0,-1);
                                                            ((MoveCharacter*)action)->setOrientation(me->getOrientation(),state::WEST);
                                                            ((MoveCharacter*)action)->setDirection(me->getDirection(),state::WEST);
                                                    }
                                                    //~ else
                                                    //~ {
                                                            //~ action = new AttackUnit(idx);
                                                            //~ ((AttackUnit*)action)->setCoords(0,-1);
                                                            //~ ((AttackUnit*)action)->setOrientation(me->getOrientation(),WEST);
                                                            //~ ((AttackUnit*)action)->setDirection(me->getDirection(),WEST);
                                                    //~ }
                                                    break;
                                        case(state::SOUTH):
                                                    std::cout << "posS " << (((state::MobileElement*)currentState.getChar(me->getY()+15*(me->getX()+1)))->getMobileTypeId()) << ":" << me->getY()+15*(me->getX()+1) << std::endl;
                                                    //~ if(((MobileElement*)currentState.getChar(me->getY()+15*(me->getX()+1)))->getMobileTypeId() == EMPTY)
                                                    {
                                                            action = new MoveCharacter(idx);
                                                            ((MoveCharacter*)action)->setCoords(1,0);
                                                            ((MoveCharacter*)action)->setOrientation(me->getOrientation(),state::SOUTH);
                                                            ((MoveCharacter*)action)->setDirection(me->getDirection(),state::SOUTH);
                                                    }
                                                    //~ else
                                                    //~ {
                                                            //~ action = new AttackUnit(idx);
                                                            //~ ((AttackUnit*)action)->setCoords(1,0);
                                                            //~ ((AttackUnit*)action)->setOrientation(me->getOrientation(),SOUTH);
                                                            //~ ((AttackUnit*)action)->setDirection(me->getDirection(),SOUTH);
                                                    //~ }
                                                    break;
                                            default:
                                                    break;
                                    }
                                    actions.add(action);
                                    actions.apply();
                                    break;
                    }
            }
    }
};
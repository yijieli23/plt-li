/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "IncEpoch.h"
#include "state/State.h"
namespace engine{
    IncEpoch::IncEpoch()
    {
        
    }
    void IncEpoch::apply(state::State& s, bool notify)
    {
        s.setEpoch(s.getEpoch()+1);
    }
    void IncEpoch::undo(state::State& s, bool notify)
    {
        s.setEpoch(s.getEpoch()-1);
    }
}
// Generated by dia2code
#ifndef ENGINE__ATTACKUNIT__H
#define ENGINE__ATTACKUNIT__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "state/Direction.h"
#include "Action.h"

namespace engine {

  /// class AttackUnit - 
  class AttackUnit : public engine::Action {
    // Attributes
  protected:
    int idx;
    int dx;
    int dy;
    state::Direction prevOrientation;
    state::Direction newOrientation;
    state::Direction prevDirection;
    state::Direction newDirection;
    int newHp;
    int prevHp;
    // Operations
  public:
    AttackUnit (int idx);
    void setCoords (int dx, int dy);
    void setOrientation (state::Direction prev, state::Direction next);
    void setDirection (state::Direction prev, state::Direction next);
    void setHp (int prev, int next);
    void apply (state::State& s, bool notify);
    void undo (state::State& s, bool notify);
  };

};

#endif

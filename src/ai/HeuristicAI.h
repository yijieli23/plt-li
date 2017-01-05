// Generated by dia2code
#ifndef AI__HEURISTICAI__H
#define AI__HEURISTICAI__H


namespace state {
  class State;
};
namespace engine {
  class CommandSet;
};
namespace ai {
  class DumbAI;
}

#include "DumbAI.h"
#include "state/State.h"
#include "engine/CommandSet.h"

namespace ai {

  /// class HeuristicAI - 
  class HeuristicAI : public ai::DumbAI {
    // Operations
  public:
    HeuristicAI (const state::State& mainState);
    void run (engine::CommandSet& commands);
  protected:
    bool moveToClosest (engine::CommandSet& commands, const Pathmap& map, int idx, int dir = 1);
  };

};

#endif

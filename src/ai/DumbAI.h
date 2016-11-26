// Generated by dia2code
#ifndef AI__DUMBAI__H
#define AI__DUMBAI__H


namespace engine {
  class CommandSet;
};
namespace state {
  class State;
};
namespace ai {
  class AI;
}

#include "AI.h"
#include "engine/CommandSet.h"

namespace ai {

  /// class DumbAI - 
  class DumbAI : public ai::AI {
    // Operations
  public:
    void dumbMove (int idx, engine::CommandSet& commands);
    DumbAI (const state::State& mainState);
    void run (engine::CommandSet& commands);
  };

};

#endif

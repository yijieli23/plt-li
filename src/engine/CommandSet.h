// Generated by dia2code
#ifndef ENGINE__COMMANDSET__H
#define ENGINE__COMMANDSET__H

#include <vector>

namespace engine {
  class Command;
  class CommandSet;
}

#include "Command.h"
#include "CommandTypeId.h"

namespace engine {

  /// class CommandSet - 
  class CommandSet {
    // Associations
    // Attributes
  public:
    std::vector<Command*> commands;
    // Operations
  public:
    ~CommandSet ();
    int size () const;
    Command* get (int category) const;
    void set (Command* cmd);
    void take (CommandSet& commands, bool replace);
  };

};

#endif
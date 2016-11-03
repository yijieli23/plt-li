// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H

#include <string>

namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"
#include "../state/ElementAlloc.h"
namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    std::string file_name;
    // Operations
  public:
    LoadCommand (const char* f);
    CommandTypeId getTypeId () const;
    const char* getFileName () const;
    void setFileName (std::string file_name);
  };

};

#endif
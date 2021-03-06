// Generated by dia2code
#ifndef STATE__HOUSE__H
#define STATE__HOUSE__H

#include <vector>

namespace state {
  class Element;
  class StaticElement;
}

#include "StaticElement.h"

namespace state {

  /// class House - 
  class House : public state::StaticElement {
    // Operations
  public:
    House ();
    Element* clone () const;
    void beingattacked ();
    void init (std::vector<int>& level);
  };

};

#endif

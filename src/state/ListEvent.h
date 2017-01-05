// Generated by dia2code
#ifndef STATE__LISTEVENT__H
#define STATE__LISTEVENT__H


namespace state {
  class ElementList;
  class StateEvent;
}

#include "StateEvent.h"

namespace state {

  /// class ListEvent - 
  class ListEvent : public state::StateEvent {
    // Attributes
  public:
    const ElementList& List;
    int idx;
    // Operations
  public:
    ListEvent (const ElementList& list, int idx);
    StateEvent* clone () const;
  };

};

#endif

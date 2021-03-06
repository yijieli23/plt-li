// Generated by dia2code
#ifndef STATE__STATICELEMENT__H
#define STATE__STATICELEMENT__H


namespace state {
  class Element;
}

#include "Element.h"
#include "StaticElementTypeId.h"

namespace state {

  /// class StaticElement - 
  class StaticElement : public state::Element {
    // Associations
    state::StaticElementTypeId StaticElementTypeId;
    // Operations
  public:
    bool isStatic () const;
  };

};

#endif

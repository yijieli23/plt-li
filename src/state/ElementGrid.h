// Generated by dia2code
#ifndef STATE__ELEMENTGRID__H
#define STATE__ELEMENTGRID__H


namespace state {
  class State;
  class ElementGrid;
  class Element;
  class ElementList;
}

#include "ElementList.h"

namespace state {

  /// class ElementGrid - 
  class ElementGrid : public state::ElementList {
    // Attributes
  protected:
    int width;
    int height;
    // Operations
  public:
    ElementGrid (State& s);
    ElementGrid* clone () const;
    void copy (const ElementGrid& other);
    bool equals (const ElementGrid& other) const;
    bool hasCell (int i, int j) const;
    int getWidth () const;
    int getHeight () const;
    Element* getCell (int i, int j) const;
    void setWidth (int w);
    void setHeight (int h);
    void setCell (int i, int j, Element* e);
    void load (const char* file_name);
    void notifyObservers (int i = -1, int j = -1) const;
  };

};

#endif

// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {
  class Element;
}

#include "Direction.h"
#include "TypeId.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    Direction orientation;
    int life;
    // Operations
  public:
    Element ();
    virtual ~Element ();
    virtual bool const isStatic () = 0;
    virtual Element* const clone () = 0;
    bool const equals (const Element& other);
    int const getX ();
    int const getY ();
    Direction const getOrientation ();
    int const getLife ();
    void setX (int x);
    void setY (int y);
    void setOrientation (Direction o);
    void setLife (int lifenum);
  };

};

#endif

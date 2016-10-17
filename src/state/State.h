// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementList;
  class ElementGrid;
  class State;
  class MobileElement;
  class ElementFactory;
  class StateEvent;
  class Observable;
}

#include "ElementList.h"
#include "ElementGrid.h"
#include "StateEventId.h"
#include "Observable.h"

namespace state {

  /// class State - 
  class State : public state::Observable {
    // Associations
    // Attributes
  protected:
    ElementList chars;
    ElementGrid grid;
    /// 		
    int epoch;
    // Operations
  public:
    State ();
    ~State ();
    State* clone () const;
    void copy (const State& other);
    bool equals (const State& other) const;
    int getEpoch () const;
    const ElementGrid& getGrid () const;
    ElementGrid& getGrid ();
    const ElementList& getChars () const;
    ElementList& getChars ();
    const MobileElement* getChar (int idx) const;
    MobileElement* getChar (int idx);
    void setElementFactory (ElementFactory* f);
    void setEpoch (int time);
    void setGrid (const ElementGrid& eg);
    void setChars (const ElementList& el);
    void loadLevel (const char* filename);
    void loadChars (const char* filename);
    void notifyObservers (StateEventId id) const;
    /// 	
    /// @param e		(???) 
    void notifyObservers (const StateEvent& e) const;
  };

};

#endif

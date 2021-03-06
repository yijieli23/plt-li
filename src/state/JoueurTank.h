// Generated by dia2code
#ifndef STATE__JOUEURTANK__H
#define STATE__JOUEURTANK__H

#include <vector>

namespace state {
  class Element;
  class MobileElement;
}

#include "MobileElement.h"

namespace state {

  /// class JoueurTank - 
  class JoueurTank : public state::MobileElement {
    // Operations
  public:
    JoueurTank ();
    bool isJoueurTank ();
    Element* clone () const;
    void addlife (int lifenum);
    void moveleft (std::vector<int>& level);
    void moveright (std::vector<int>& level);
    void moveup (std::vector<int>& level);
    void movedown (std::vector<int>& level);
    void wait ();
    void init (std::vector<int>& level);
  };

};

#endif

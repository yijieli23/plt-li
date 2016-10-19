// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H


namespace render {
  class Tile;
}

#include "Tile.h"
#include "../state/Element.h"
namespace render {

  /// class TileSet - 
  class TileSet {
    // Associations
    // Operations
  public:
    virtual ~TileSet ();
    virtual int getCellWidth () const = 0;
    virtual int getCellHeight () const = 0;
    virtual const char* getImageFile () const = 0;
    virtual const Tile* getElementTile (const state::Element* e) const = 0;
  };

};

#endif

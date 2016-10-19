// Generated by dia2code
#ifndef RENDER__STATICTILE__H
#define RENDER__STATICTILE__H


namespace render {
  class Tile;
}

#include "Tile.h"

namespace render {

  /// class StaticTile - 
  class StaticTile : public render::Tile {
    // Attributes
  protected:
    int x;
    int y;
    int width;
    int height;
    // Operations
  public:
    StaticTile (int x, int y);
    bool isAnimated () const;
    int getX () const;
    int getY () const;
    int getHeight () const;
    int getWidth () const;
    void setX (int x);
    void setY (int y);
    void setWidth (int w);
    void setHeight (int h);
  };

};

#endif

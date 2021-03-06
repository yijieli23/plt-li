// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H


namespace render {
  class StaticTile;
}

namespace render {

  /// class Surface - 
  class Surface {
    // Operations
  public:
    Surface ();
    virtual ~Surface ();
    void clear ();
    void loadTexture (const char* image_file);
    void setSpriteCount (int n);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const StaticTile* tex);
    int afficher ();
    void update ();
    void multith (int n);
  };

};

#endif

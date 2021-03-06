// Generated by dia2code
#ifndef RENDER__SFMLSURFACE__H
#define RENDER__SFMLSURFACE__H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace render {
  class StaticTile;
  class Surface;
};
namespace sf {
  class Transformable;
  class Drawable;
}

#include "Surface.h"

namespace render {

  /// class SFMLSurface - 
  class SFMLSurface : public render::Surface, public sf::Transformable, public sf::Drawable {
    // Attributes
  protected:
    sf::VertexArray vertices;
    sf::Texture tileset;
    sf::Vertex* quad;
    // Operations
  public:
    void clear ();
    void loadTexture (const char* image_file);
    void setSpriteCount (int n);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const StaticTile* tex);
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    bool load (const std::string& tileset, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height);
  };

};

#endif

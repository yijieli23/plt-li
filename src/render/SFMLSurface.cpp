/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SFMLSurface.h"
#include <iostream>
#include "StaticTile.h"




namespace render{
    void SFMLSurface::clear()
{
	vertices.clear();
}

void SFMLSurface::loadTexture(const char* ts)
{	
	if (!tileset.loadFromFile(ts))
		std::cerr << "Error loading tileset" << std::endl;
}

void SFMLSurface::setSpriteCount(int nb)
{
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(4 * nb);
}

void SFMLSurface::setSpriteLocation(int i,int x, int y)
{
	quad = &vertices[i * 4];
	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + 16, y);
	quad[2].position = sf::Vector2f(x + 16, y + 16);
	quad[3].position = sf::Vector2f(x, y + 16);
}

void SFMLSurface::setSpriteTexture(int i, const StaticTile* tile)
{	
	int x = tile->getX();
	int y = tile->getY();
	int width = tile->getWidth();
	int height = tile->getHeight();
	quad = &vertices[i * 4];
	quad[0].texCoords = sf::Vector2f(x, y);
	quad[1].texCoords = sf::Vector2f(x + width, y);
	quad[2].texCoords = sf::Vector2f(x + width, y + height);
	quad[3].texCoords = sf::Vector2f(x, y + height);
}

void SFMLSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        states.texture = &tileset;

        target.draw(vertices, states);
    }
bool SFMLSurface::load(const std::string& tileset1, sf::Vector2u tileSize, std::vector<int>& tiles, unsigned int width, unsigned int height)
    {
        if (!tileset.loadFromFile(tileset1))
            return false;

        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(width * height * 4);

        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                int tileNumber = tiles[i + j * width];

                int tu = tileNumber % (tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (tileset.getSize().x / tileSize.x);

                sf::Vertex* quad = &vertices[(i + j * width) * 4];

                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }
    
};
#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
  public:
    void load(std::string const& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray vertices;
    sf::Texture tilesetTexture;
};

#endif // !TILEMAP_H

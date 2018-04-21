#include "Content.hpp"
#include "TileMap.hpp"

void TileMap::load(std::string const& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
  tilesetTexture = Content::getTexture(tileset);

  vertices.setPrimitiveType(sf::Quads);
  vertices.resize(width * height * 4);

  int span = (tilesetTexture.getSize().x / tileSize.x);

  for (unsigned int x = 0; x < width; x += 1) {
    for (unsigned int y = 0; y < height; y += 1) {
      int tileId = tiles[x + y * width];
      int tu = tileId % span;
      int tv = tileId / span;

      sf::Vertex* quad = &vertices[(x + y * width) * 4];
      quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
      quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
      quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
      quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);
      quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
      quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
      quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
      quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
    }
  }
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = &tilesetTexture;
  target.draw(vertices, states);
}

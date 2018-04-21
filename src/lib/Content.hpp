#ifndef CONTENT_H

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class Content {
  public:
    Content();

    static sf::Texture& getTexture(std::string const& filename);

  protected:
    std::map<std::string, sf::Texture> textureCache;
    static Content* instance;
};

#endif // !CONTENT_H

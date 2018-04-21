#include <cassert>
#include <stdexcept>
#include <string>

#include "Content.hpp"

Content* Content::instance = nullptr;

Content::Content () {
  assert(Content::instance == nullptr);
  Content::instance = this;
}

sf::Texture& Content::getTexture(std::string const& filename) {
  auto& cache = instance->textureCache;
  auto pairFound = cache.find(filename);
  if (pairFound != cache.end()) {
    return pairFound->second;
  } else {
    auto& texture = cache[filename];
    if (!texture.loadFromFile(filename)) {
      throw std::runtime_error(std::string("Unable to load texture from file: ") + filename);
    }
    return texture;
  }
}

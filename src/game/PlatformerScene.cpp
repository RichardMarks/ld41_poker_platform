#include <iostream>

#include "Game.hpp"
#include "PlatformerScene.hpp"

void PlatformerScene::create() {
  const int level[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 1, 0, 1, 1, 1, 0, 0,
    0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
    0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
    0, 1, 0, 1, 0, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  tileMap.load("resources/tiles.png", sf::Vector2u(128, 128), level, 10, 10);
  tileMap.setScale(0.25f, 0.25f);
}

void PlatformerScene::destroy() {
  this->exit();
}

void PlatformerScene::enter() {
  std::cout << "entering platformer scene" << std::endl;
}

void PlatformerScene::exit() {
  std::cout << "exiting platformer scene" << std::endl;
}

void PlatformerScene::update(sf::Time const& deltaTime) {

}

void PlatformerScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();
  window.draw(tileMap);
  window.display();
}

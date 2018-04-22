#include <iostream>

#include "Game.hpp"
#include "DebugScene.hpp"

void DebugScene::create() {

}

void DebugScene::destroy() {
  this->exit();
}

void DebugScene::enter() {
  std::cout << "entering Debug scene" << std::endl;
}

void DebugScene::exit() {
  std::cout << "exiting Debug scene" << std::endl;
}

void DebugScene::update(sf::Time const& deltaTime) {

}

void DebugScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

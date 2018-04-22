#include <iostream>

#include "Game.hpp"
#include "DevScene.hpp"

void DevScene::create() {

}

void DevScene::destroy() {
  this->exit();
}

void DevScene::enter() {
  std::cout << "entering Dev scene" << std::endl;
}

void DevScene::exit() {
  std::cout << "exiting Dev scene" << std::endl;
}

void DevScene::update(sf::Time const& deltaTime) {

}

void DevScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

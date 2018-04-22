#include <iostream>

#include "Game.hpp"
#include "OptionsScene.hpp"

void OptionsScene::create() {

}

void OptionsScene::destroy() {
  this->exit();
}

void OptionsScene::enter() {
  std::cout << "entering Options scene" << std::endl;
}

void OptionsScene::exit() {
  std::cout << "exiting Options scene" << std::endl;
}

void OptionsScene::update(sf::Time const& deltaTime) {

}

void OptionsScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

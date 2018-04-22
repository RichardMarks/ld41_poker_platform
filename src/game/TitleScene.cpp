#include <iostream>

#include "Game.hpp"
#include "TitleScene.hpp"

void TitleScene::create() {

}

void TitleScene::destroy() {
  this->exit();
}

void TitleScene::enter() {
  std::cout << "entering Title scene" << std::endl;
}

void TitleScene::exit() {
  std::cout << "exiting Title scene" << std::endl;
}

void TitleScene::update(sf::Time const& deltaTime) {

}

void TitleScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

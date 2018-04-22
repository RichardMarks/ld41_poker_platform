#include <iostream>

#include "Game.hpp"
#include "CreditsScene.hpp"

void CreditsScene::create() {

}

void CreditsScene::destroy() {
  this->exit();
}

void CreditsScene::enter() {
  std::cout << "entering Credits scene" << std::endl;
}

void CreditsScene::exit() {
  std::cout << "exiting Credits scene" << std::endl;
}

void CreditsScene::update(sf::Time const& deltaTime) {

}

void CreditsScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

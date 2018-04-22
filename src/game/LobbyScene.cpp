#include <iostream>

#include "Game.hpp"
#include "LobbyScene.hpp"

void LobbyScene::create() {

}

void LobbyScene::destroy() {
  this->exit();
}

void LobbyScene::enter() {
  std::cout << "entering Lobby scene" << std::endl;
}

void LobbyScene::exit() {
  std::cout << "exiting Lobby scene" << std::endl;
}

void LobbyScene::update(sf::Time const& deltaTime) {

}

void LobbyScene::render() {
  sf::RenderWindow& window = gamePtr->window;
  window.clear();

  window.display();
}

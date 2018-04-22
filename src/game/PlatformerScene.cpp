#include <iostream>

#include "Game.hpp"
#include "PlatformerScene.hpp"
#include "TitleScene.hpp"

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

  auto wSize = gamePtr->window.getSize();

  sf::View leftView(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));
  sf::View rightView(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));

  leftView.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
  rightView.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1));

  viewList.push_back(leftView);
  viewList.push_back(rightView);
}

void PlatformerScene::destroy() {
  this->exit();
}

void PlatformerScene::enter() {
  std::cout << "entering platformer scene" << std::endl;
}

void PlatformerScene::exit() {
  std::cout << "exiting platformer scene" << std::endl;
  gamePtr->window.setView(gamePtr->mainView);
}

void PlatformerScene::update(sf::Time const& deltaTime) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
    std::cout << "changing scene" << std::endl;
    gamePtr->changeScene(new TitleScene(gamePtr));
  }
}

void PlatformerScene::render() {
  sf::RenderWindow& window = gamePtr->window;

  window.clear(sf::Color::Red);

  for (auto it = viewList.begin(); it != viewList.end(); ++it) {
    window.setView(*it);
    window.draw(tileMap);
  }

  window.display();
}

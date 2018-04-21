#include "Game.hpp"

Game::Game() {
  paused = false;
  pausedFromFocusChange = false;
  window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
  create();
  while (window.isOpen()) {
    sf::Event sfEvent;
    while (window.pollEvent(sfEvent)) {
      if (sfEvent.type == sf::Event::Closed) {
        window.close();
      } else if (sfEvent.type == sf::Event::LostFocus) {
        pausedStatusBeforeFocusChange = paused;
        paused = true;
        pausedFromFocusChange = true;
      } else if (sfEvent.type == sf::Event::GainedFocus) {
        paused = false;
        if (pausedFromFocusChange) {
          paused = pausedStatusBeforeFocusChange;
        }
      } else if (sfEvent.type == sf::Event::KeyReleased) {
        if (sfEvent.key.code == sf::Keyboard::Key::Escape) {
          window.close();
        }
      }
    }
    if (!paused) {
      update();
    }
    render();
  }
}

Game::~Game() {
  destroy();
}

void Game::create() {
  mainView.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
  window.setView(mainView);
}

void Game::destroy() {

}

void Game::update() {

}

void Game::render() {
  window.clear();
  window.display();
}

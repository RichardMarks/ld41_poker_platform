#include "Game.hpp"
#include "lib/SpriteData.hpp"

Game::Game()
  : playerSpriteAnimator(playerSprite) {
  paused = false;
  pausedFromFocusChange = false;
  window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
  create();
  sf::Clock sfClock;
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
      sf::Time deltaTime = sfClock.restart();
      update(deltaTime);
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

  auto& idleAnimation = playerSpriteAnimator.createAnimation(
    "idle", "resources/player.png", sf::seconds(0.5), true);
  SpriteData playerSpriteData("resources/player.txt");

  std::vector<std::string> framesRequested;
  // framesRequested.push_back("alienGreen_front.png");
  // framesRequested.push_back("alienGreen_jump.png");
  // framesRequested.push_back("alienGreen_stand.png");
  framesRequested.push_back("alienGreen_walk1.png");
  framesRequested.push_back("alienGreen_walk2.png");

  std::vector<sf::IntRect> frames = playerSpriteData.frames(framesRequested);

  for (auto it = frames.begin(); it != frames.end(); ++it) {
    sf::IntRect& frame = *it;
    idleAnimation.addFrame(frame);
  }

  const sf::IntRect& rc = playerSprite.getTextureRect();
  playerSprite.setOrigin(0.5f * rc.width, 0.5f * rc.height);
  playerSprite.setScale(0.5f, 0.5f);
  playerSprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Game::destroy() {

}

void Game::update(sf::Time const& deltaTime) {
  playerSpriteAnimator.update(deltaTime);
}

void Game::render() {
  window.clear();
  window.draw(playerSprite);
  window.display();
}

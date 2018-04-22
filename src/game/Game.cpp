#include "Game.hpp"
#include "lib/SpriteData.hpp"

#include "PlatformerScene.hpp"

Game::Game()
  : playerSpriteAnimator(playerSprite),
    currentScene(nullptr),
    nextScene(nullptr) {
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

  currentScene = new PlatformerScene(this);
  currentScene->create();
  currentScene->enter();

  // auto& idleAnimation = playerSpriteAnimator.createAnimation(
  //   "idle", "resources/player.png", sf::seconds(0.5), true);
  // SpriteData playerSpriteData("resources/player.txt");

  // std::vector<std::string> framesRequested;
  // // framesRequested.push_back("alienGreen_front.png");
  // // framesRequested.push_back("alienGreen_jump.png");
  // // framesRequested.push_back("alienGreen_stand.png");
  // framesRequested.push_back("alienGreen_walk1.png");
  // framesRequested.push_back("alienGreen_walk2.png");

  // std::vector<sf::IntRect> frames = playerSpriteData.frames(framesRequested);

  // for (auto it = frames.begin(); it != frames.end(); ++it) {
  //   sf::IntRect& frame = *it;
  //   idleAnimation.addFrame(frame);
  // }

  // const sf::IntRect& rc = playerSprite.getTextureRect();
  // playerSprite.setOrigin(0.5f * rc.width, 0.5f * rc.height);
  // playerSprite.setScale(0.5f, 0.5f);
  // playerSprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  // const int level[] = {
  //   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //   0, 1, 0, 1, 0, 1, 1, 1, 0, 0,
  //   0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
  //   0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
  //   0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
  //   0, 1, 0, 1, 0, 1, 1, 1, 0, 0,
  //   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  // };
  // tileMap.load("resources/tiles.png", sf::Vector2u(128, 128), level, 10, 10);
  // tileMap.setScale(0.25f, 0.25f);
}

void Game::destroy() {
  if (currentScene != nullptr) {
    currentScene->destroy();
    delete currentScene;
    currentScene = nullptr;
  }
}

void Game::update(sf::Time const& deltaTime) {
  if (currentScene != nullptr) {
    currentScene->update(deltaTime);
  }

  if (nextScene != nullptr) {
    if (currentScene != nullptr) {
      currentScene->exit();
      delete currentScene;
      currentScene = nullptr;
    }
    nextScene->enter();
    currentScene = nextScene;
    nextScene = nullptr;
  }
  // playerSpriteAnimator.update(deltaTime);
}

void Game::render() {
  if (currentScene != nullptr) {
    currentScene->render();
  }

  // window.clear();
  // window.draw(tileMap);
  // window.draw(playerSprite);
  // window.display();
}

void Game::changeScene(SceneInterface* next) {
  nextScene = next;
}

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "lib/SpriteAnimator.hpp"
// #include "lib/TileMap.hpp"

#include "SceneInterface.hpp"

#define SCREEN_WIDTH 1920 / 2
#define SCREEN_HEIGHT 1080 / 2
#define WINDOW_TITLE "LD41 #LDJAM - Poker Platform"

class Game {
  public:
    Game ();
    ~Game ();

    sf::RenderWindow window;
    sf::View mainView;

    inline void pause () {
      paused = true;
      pausedFromFocusChange = false;
    }

    inline void resume () {
      paused = false;
    }

    void changeScene(SceneInterface* nextScene);

  private:
    void create();
    void destroy();
    void update(sf::Time const& deltaTime);
    void render();

    bool paused;
    bool pausedFromFocusChange;
    bool pausedStatusBeforeFocusChange;

    sf::Sprite playerSprite;
    SpriteAnimator playerSpriteAnimator;

    // TileMap tileMap;
    SceneInterface* currentScene;
    SceneInterface* nextScene;
};

#endif // !GAME_H

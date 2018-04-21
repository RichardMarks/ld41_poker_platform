#ifndef GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "lib/SpriteAnimator.hpp"
#include "lib/TileMap.hpp"

#define SCREEN_WIDTH 1920 / 2
#define SCREEN_HEIGHT 1080 / 2
#define WINDOW_TITLE "LD41 #LDJAM - Poker Platform"

class Game {
  public:
    Game ();
    ~Game ();

  private:
    void create();
    void destroy();
    void update(sf::Time const& deltaTime);
    void render();

    sf::RenderWindow window;
    sf::View mainView;

    bool paused;
    bool pausedFromFocusChange;
    bool pausedStatusBeforeFocusChange;

    sf::Sprite playerSprite;
    SpriteAnimator playerSpriteAnimator;

    TileMap tileMap;
};

#endif // !GAME_H

#ifndef GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define SCREEN_WIDTH 1920 / 2
#define SCREEN_HEIGHT 1080 / 2
#define WINDOW_TITLE "LD41 #LDJAM - Jump 'N Poker"

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
};

#endif // !GAME_H

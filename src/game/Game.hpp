#ifndef GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE "SFML Game Development Starter"

class Game {
  public:
    Game ();
    ~Game ();

  private:
    void create();
    void destroy();
    void update();
    void render();

    sf::RenderWindow window;
    sf::View mainView;

    bool paused;
    bool pausedFromFocusChange;
    bool pausedStatusBeforeFocusChange;
};

#endif // !GAME_H

#ifndef SCENE_INTERFACE_H
#define SCENE_INTERFACE_H

#include <SFML/Graphics.hpp>

class Game;

class SceneInterface {
  public:
    SceneInterface(Game* game)
      : gamePtr(game) {
    }

    virtual ~SceneInterface() {}

    virtual void create() = 0;
    virtual void destroy() = 0;
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update(sf::Time const& deltaTime) = 0;
    virtual void render() = 0;

  protected:
    Game* gamePtr;
};

#endif // !SCENE_INTERFACE_H

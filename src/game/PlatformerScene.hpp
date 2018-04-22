#ifndef PLATFORMER_SCENE
#define PLATFORMER_SCENE

#include "SceneInterface.hpp"

#include "lib/TileMap.hpp"

class PlatformerScene : public SceneInterface {
  public:
    PlatformerScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
    TileMap tileMap;
};

#endif // !PLATFORMER_SCENE

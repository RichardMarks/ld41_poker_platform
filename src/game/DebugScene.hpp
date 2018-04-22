#ifndef DEBUG_SCENE
#define DEBUG_SCENE

#include "SceneInterface.hpp"

class DebugScene : public SceneInterface {
  public:
    DebugScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !DEBUG_SCENE

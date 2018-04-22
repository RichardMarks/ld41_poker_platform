#ifndef DEV_SCENE
#define DEV_SCENE

#include "SceneInterface.hpp"

class DevScene : public SceneInterface {
  public:
    DevScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !DEV_SCENE

#ifndef OPTIONS_SCENE
#define OPTIONS_SCENE

#include "SceneInterface.hpp"

class OptionsScene : public SceneInterface {
  public:
    OptionsScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !OPTIONS_SCENE

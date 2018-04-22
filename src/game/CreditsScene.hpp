#ifndef CREDITS_SCENE
#define CREDITS_SCENE

#include "SceneInterface.hpp"

class CreditsScene : public SceneInterface {
  public:
    CreditsScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !CREDITS_SCENE

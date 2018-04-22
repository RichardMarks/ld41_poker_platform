#ifndef TITLE_SCENE
#define TITLE_SCENE

#include "SceneInterface.hpp"

class TitleScene : public SceneInterface {
  public:
    TitleScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !TITLE_SCENE

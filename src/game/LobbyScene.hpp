#ifndef LOBBY_SCENE
#define LOBBY_SCENE

#include "SceneInterface.hpp"

class LobbyScene : public SceneInterface {
  public:
    LobbyScene(Game* game)
      : SceneInterface(game) {}
    virtual void create();
    virtual void destroy();
    virtual void enter();
    virtual void exit();
    virtual void update(sf::Time const& deltaTime);
    virtual void render();

  protected:
};

#endif // !LOBBY_SCENE

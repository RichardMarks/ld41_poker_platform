#include <iostream>
#include <stdexcept>

#include "game/Game.hpp"
#include "lib/Content.hpp"

int main(int argc, char* argv[]) {
  try {
    Content contentManagerSingletonInstance;
    Game game;
  } catch(const std::exception& ex) {
    std::cerr << "Runtime Error: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

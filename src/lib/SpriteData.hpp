#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class SpriteData {
  public:
    SpriteData(std::string const& filename);
    std::vector<sf::IntRect> frames(std::vector<std::string> framesRequested);
  private:
    std::map<std::string, sf::IntRect> allFrames;
};

// int main() {

//   SpriteData data("data.txt");

//   std::vector<std::string> framesRequested;

//   framesRequested.push_back("alienGreen_front.png");
//   framesRequested.push_back("alienGreen_jump.png");
//   framesRequested.push_back("alienGreen_stand.png");

//   std::vector<sf::IntRect> frames = data.frames(framesRequested);

//   for (auto it = frames.begin(); it != frames.end(); ++it) {
//     sf::IntRect& frame = *it;
//     std::cout
//       << "{ " << frame.x
//       << ", " << frame.y
//       << ", " << frame.width
//       << ", " << frame.height
//       << " }" << std::endl;
//   }

// }

#endif // !SPRITE_DATA_H

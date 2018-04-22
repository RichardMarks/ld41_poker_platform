#ifndef SPRITE_ANIMATOR_H
#define SPRITE_ANIMATOR_H

#include <list>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class SpriteAnimator {
  public:
    struct Animation {
      std::string name;
      std::string textureName;
      std::vector<sf::IntRect> frames;
      sf::Time duration;
      bool looping;

      Animation(std::string const& name, std::string const& textureName, sf::Time duration, bool looping)
        : name(name), textureName(textureName), duration(duration), looping(looping) {}

      void addFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int numFrames) {
        sf::Vector2i current = startFrom;
        for (unsigned int i = 0; i < numFrames; i += 1) {
          frames.push_back(
            sf::IntRect(
              current.x,
              current.y,
              frameSize.x,
              frameSize.y
            )
          );
          current.x += frameSize.x;
        }
      }

      void addFrame(sf::IntRect& frame) {
        frames.push_back(frame);
      }
    };

    SpriteAnimator(sf::Sprite& sprite);
    SpriteAnimator::Animation& createAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool looping = true);
    void update(sf::Time const& deltaTime);
    bool selectAnimation(std::string const& name);
    std::string currentAnimationName() const;

  protected:
    SpriteAnimator::Animation* findAnimation(std::string const& name);
    void selectAnimation(SpriteAnimator::Animation* animation);

    sf::Sprite& sprite;
    sf::Time currentTime;
    std::list<SpriteAnimator::Animation> animations;
    SpriteAnimator::Animation* currentAnimation;
};

#endif // !SPRITE_ANIMATOR_H

#include "Content.hpp"
#include "SpriteAnimator.hpp"

SpriteAnimator::SpriteAnimator(sf::Sprite& sprite)
  : sprite(sprite), currentTime(), currentAnimation(nullptr) {}

SpriteAnimator::Animation& SpriteAnimator::createAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool looping) {
  animations.push_back(
    SpriteAnimator::Animation(
      name,
      textureName,
      duration,
      looping
    )
  );

  if (currentAnimation == nullptr) {
    selectAnimation(&animations.back());
  }
  return animations.back();
}

SpriteAnimator::Animation* SpriteAnimator::findAnimation(std::string const& name) {
  for (auto it = animations.begin(); it != animations.end(); ++it) {
    if (it->name == name) {
      return &*it;
    }
  }
  return nullptr;
}

void SpriteAnimator::update(sf::Time const& deltaTime) {
  if (currentAnimation == nullptr) {
    return;
  }

  currentTime += deltaTime;

  float scaledTime = (currentTime.asSeconds() / currentAnimation->duration.asSeconds());
  int numFrames = currentAnimation->frames.size();
  int currentFrame = static_cast<int>(scaledTime * numFrames);

  if (currentAnimation->looping) {
    currentFrame %= numFrames;
  } else if (currentFrame >= numFrames) {
    currentFrame = numFrames - 1;
  }

  sprite.setTextureRect(currentAnimation->frames[currentFrame]);
}

bool SpriteAnimator::selectAnimation(std::string const& name) {
  auto anim = findAnimation(name);
  if (anim != nullptr) {
    selectAnimation(anim);
    return true;
  }
  return false;
}

void SpriteAnimator::selectAnimation(SpriteAnimator::Animation* animation) {
  if (animation != nullptr) {
    sprite.setTexture(Content::getTexture(animation->textureName));
  }
  currentAnimation = animation;
  currentTime = sf::Time::Zero;
}

std::string SpriteAnimator::currentAnimationName() const {
  if (currentAnimation != nullptr) {
    return currentAnimation->name;
  }
  return "";
}

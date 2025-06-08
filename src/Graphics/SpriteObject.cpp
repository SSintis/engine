#include "../../include/Graphics/SpriteObject.hpp"

SpriteObject::SpriteObject(const std::string &title, float axisX, float axisY,
                           float scale) {
  if (!texture.loadFromFile(title)) {
    std::cout << "Error with load texture!!!" << std::endl;
  } else {
    std::cout << "Texture was loaded" << std::endl;
  }

  sprite.setTexture(texture);
  sprite.scale(sf::Vector2f(scale, scale));
  sprite.setPosition(axisX, axisY);

  rotationSprite = Rotation::UP;
}

void SpriteObject::move(float offsetX, float offsetY) {
  sprite.setPosition(sprite.getPosition().x + offsetX,
                     sprite.getPosition().y + offsetY);

  if (hitbox) {
    hitbox->setPosition(sprite.getPosition().x + offsetX,
                        sprite.getPosition().y + offsetY);
  }
}

void SpriteObject::setTextureRect(int x, int y, int height, int width) {
  sprite.setTextureRect(sf::IntRect(x, y, height, width));
}

void SpriteObject::initAnimation(int spriteWidth, int spriteHeight) {
  this->spriteWidth = spriteWidth;
  this->spriteHeight = spriteHeight;

  sprite.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));
}

void SpriteObject::updateAnimation(Rotation rot) {
  if (rot == Rotation::UP) {
    sprite.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));
  } else if (rot == Rotation::DOWN) {
    sprite.setTextureRect(
        sf::IntRect(0, 2 * spriteHeight, spriteWidth, spriteHeight));
  } else if (rot == Rotation::LEFT) {
    sprite.setTextureRect(
        sf::IntRect(0, spriteHeight, spriteWidth, spriteHeight));
  } else if (rot == Rotation::RIGHT) {
    sprite.setTextureRect(
        sf::IntRect(0, 3 * spriteHeight, spriteWidth, spriteHeight));
  }
}

void SpriteObject::setHitbox(float offsetX, float offsetY, float width,
                             float height) {
  hitbox = new Hitbox(sprite.getPosition().x + offsetX,
                      sprite.getPosition().y + offsetY, width, height);
}

Hitbox *SpriteObject::getHitbox() const { return hitbox; }

void SpriteObject::setCollider(float offsetX, float offsetY, float width,
                               float height) {
  if (collider == nullptr) {
    collider = new Collider(sprite, offsetX, offsetY, width, height);
  } else {
    collider->setOffset(offsetX, offsetY);
    collider->setSize(width, height);
  }
}

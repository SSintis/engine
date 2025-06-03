//default, minimalist, space-vim-dark


#pragma once
#include <SFML/Graphics.hpp>

#include "Hitbox.hpp"
#include "../Physics/Collider.hpp"

#include <string>
#include <iostream>

enum class Rotation{ LEFT, RIGHT, UP, DOWN };

class SpriteObject{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    Hitbox* hitbox = nullptr;
    Collider* collider = nullptr;

    int spriteWidth, spriteHeight;
    Rotation rotationSprite;
    
public:
    SpriteObject(const std::string& title, float axisX, float axisY, float scale);

    sf::Sprite& returnSpriteObject(){ return sprite; }

    void initAnimation(int spriteWidth, int spriteHeight);
    void updateAnimation(Rotation rot);

    void setTextureRect(int x, int y, int height, int width);
    void move(float offsetX, float offsetY);

    void setHitbox(float offsetX, float offsetY, float width, float height);
    Hitbox* getHitbox() const;

    Collider* getCollider() const { return collider; }
    void setCollider(float offsetX = 0, float offsetY = 0, float width = 0, float height = 0);
};

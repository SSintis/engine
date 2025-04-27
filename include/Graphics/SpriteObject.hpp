#pragma once
#include <SFML/Graphics.hpp>
#include "Hitbox.hpp"
#include <string>
#include <iostream>

enum class Rotation{ LEFT, RIGHT, UP, DOWN };

class SpriteObject{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    Hitbox* hitbox = nullptr;

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
};
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

enum class Rotation{ LEFT, RIGHT, UP, DOWN };

class SpriteObject{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    int spriteWidth, spriteHeight;
    Rotation rotationSprite;
    
public:
    SpriteObject(const std::string& title, float axisX, float axisY, float scale);

    sf::Sprite& returnSpriteObject(){ return sprite; }

    void initAnimation(int spriteWidth, int spriteHeight);
    void updateAnimation(Rotation rot);

    void setTextureRect(int x, int y, int height, int width);
    void move(float x, float y);
};
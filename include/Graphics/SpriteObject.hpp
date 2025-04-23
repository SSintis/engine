#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class SpriteObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    SpriteObject(const std::string& title, float axisX, float axisY);
    sf::Sprite returnSpriteObject(){ return sprite; }
};
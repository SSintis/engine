#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.hpp"
#include <vector>

class RenderSystem
{
private:
    static inline std::vector<SpriteObject> bufferForRender;
public:
    static void RenderObject(sf::RenderWindow* _window);
    static void addNewSprite(SpriteObject newObject);
};
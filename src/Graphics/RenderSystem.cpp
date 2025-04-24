#include "../../include/Graphics/RenderSystem.hpp"
#include <iostream>

void RenderSystem::RenderObject(sf::RenderWindow* _window){
	for (int i = 0; i < bufferForRender.size(); i++){
        _window->draw(bufferForRender[i].returnSpriteObject());
    }
}

void RenderSystem::addNewSprite(SpriteObject newObject){
    bufferForRender.push_back(newObject);
}
#include "../../include/Graphics/RenderSystem.hpp"
#include <iostream>

void RenderSystem::RenderObject(sf::RenderWindow* _window){
	for (int i = 0; i < bufferForRender.size(); i++){
        _window->draw(bufferForRender[i]->returnSpriteObject());
        if (bufferForRender[i]->getHitbox()) {
            bufferForRender[i]->getHitbox()->draw(_window);
        }
        //std::cout<<bufferForRender[i]->returnSpriteObject().getPosition().y << std::endl;
    }
}

void RenderSystem::addNewSprite(SpriteObject* newObject){
    bufferForRender.push_back(newObject);
}

RenderSystem::~RenderSystem(){
    for(int i = 0; i < bufferForRender.size(); i++) { delete bufferForRender[i]; }
}
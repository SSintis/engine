#include "../../include/Graphics/RenderSystem.hpp"
#include <iostream>

void RenderSystem::RenderObject(sf::RenderWindow* _window){
	for (int i = 0; i < bufferForRender.size(); i++){
        _window->draw(bufferForRender[i]->returnSpriteObject());
        if (bufferForRender[i]->getHitbox()) {
            bufferForRender[i]->getHitbox()->draw(_window);
        }

        if (bufferForRender[i]->getCollider() && showCollider) {
            sf::FloatRect bounds = bufferForRender[i]->getCollider()->getBounds();
            sf::RectangleShape rect(sf::Vector2f(bounds.width, bounds.height));
            rect.setPosition(bounds.left, bounds.top);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineColor(sf::Color::Blue);
            rect.setOutlineThickness(1.f);
            _window->draw(rect);
        }
    }

    for (int i = 0; i < bufferForRenderText.size(); i++) _window->draw(*bufferForRenderText[i]);
}

void RenderSystem::addNewSprite(SpriteObject* newObject){
    bufferForRender.push_back(newObject);
}

void RenderSystem::addNewText(sf::Text* newText){
    bufferForRenderText.push_back(newText);
}

void RenderSystem::deleteSprite(SpriteObject* Object){
  for (int i = 0 ; i < bufferForRender.size() ; i++ ) {
      if(bufferForRender[i] == Object){ 
          bufferForRender.erase(bufferForRender.begin() + i);
          return;
      }
  }
}

void RenderSystem::editSettings(Setting argument){
    switch (argument)
    {
    case Setting::DRAW_COLLIDER : showCollider = true; break;
    case Setting::NOT_DRAW_COLLIDER : showCollider = false; break;
    default: break;
    }
}

RenderSystem::~RenderSystem(){
    for(int i = 0; i < bufferForRender.size(); i++) { delete bufferForRender[i]; }
}

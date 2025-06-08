#include "../../include/Graphics/RenderSystem.hpp"
#include <SFML/Graphics.hpp>

void RenderSystem::SearchAndRender(EntityManeger& em, sf::RenderWindow* _window){
  for(int i = 0 ; em.getSizeOfArray() - 1 ; i++){
    if(em.getEntityPerIterator(i)->hasComponent<Sprite>()){
      _window->draw(em.getEntityPerIterator(i)->getComponent<Sprite>()->sprite);
    }
  }
}

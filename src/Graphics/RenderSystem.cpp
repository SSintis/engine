#include "../../include/Graphics/RenderSystem.hpp"

#include "../../include/ECS/baseComponent/Layer.hpp"
#include "../../include/ECS/baseComponent/Sprite.hpp"

#include <SFML/Graphics.hpp>
#include <algorithm>

void RenderSystem::SearchAndRender(EntityManeger& em, sf::RenderWindow* _window){
  std::vector<Entity*> entities = em.getEntitiesWithComponent<Layer>();
  std::sort(entities.begin(), entities.end());

  for(auto& en : entities){
    if(en->hasComponent<Sprite>()){ _window->draw(en->getComponent<Sprite>()->sprite); }
  }
}

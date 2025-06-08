#include "../../include/Graphics/RenderSystem.hpp"

#include "../../include/ECS/baseComponent/Layer.hpp"

#include <SFML/Graphics.hpp>

void RenderSystem::SearchAndRender(EntityManeger& em, sf::RenderWindow* _window){
  std::vector<Entity*> entities = em.getEntitiesWithComponent<Layer>();

}

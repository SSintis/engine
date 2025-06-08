#pragma once

#include "../ECS/Entity.hpp"

#include <memory>
#include <vector>

class EntityManeger {
private:
  std::vector<std::unique_ptr<Entity>> listOfEntities;
  int maxCountOfEntity;

public:
  EntityManeger();
  EntityManeger(int maxSize) : maxCountOfEntity(maxSize){ } 

  Entity* createEntity();
  void removeEntity(Entity* entity);
  
  int getSizeOfArray() { return listOfEntities.size(); }
  
  template<typename T>
  std::vector<Entity*> getEntitiesWithComponent();
};

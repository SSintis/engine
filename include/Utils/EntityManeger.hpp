#pragma once

#include "../ECS/Entity.hpp"

#include <memory>
#include <vector>

class EntityManeger {
private:
  std::vector<std::unique_ptr<Entity>> listOfEntities;
  int maxCountOfEntity;

public:
  EntityManeger(int maxCountOfEntity = 0) : maxCountOfEntity(maxCountOfEntity) {}

  Entity* createEntity();
  void removeEntity(Entity* entity);
  
  void Update();

  int getSizeOfArray() { return listOfEntities.size(); }
  
  template<typename T>
  std::vector<Entity*> getEntitiesWithComponent(){
    std::vector<Entity*> entities;
    for(auto& en : listOfEntities){
      if(en->hasComponent<T>()) { entities.push_back(en.get()); }
    }
  return entities;
  }
};

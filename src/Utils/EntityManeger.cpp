#include "../../include/Utils/EntityManeger.hpp"
#include <algorithm>

Entity* EntityManeger::createEntity(){
  auto entity = std::make_unique<Entity>();
  Entity* rawPtr = entity.get();
  listOfEntities.push_back(entity);

  return rawPtr;
}

void EntityManeger::removeEntity(Entity* entity){
  auto it = std::find_if(
    listOfEntities.begin(),
    listOfEntities.end(),
    [entity](const auto& ptr) { return ptr.get() == entity; }
  );
  if (it != listOfEntities.end()) {
    listOfEntities.erase(it);
  }
}

template <typename T>
std::vector<Entity*> EntityManeger::getEntitiesWithComponent(){
  std::vector<Entity*> entities;
  for(auto& en : listOfEntities){
    if(en->hasComponent<T>()){ entities.push_back(en.get()); }
  }
  return entities;
}

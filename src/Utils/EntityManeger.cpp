#include "../../include/Utils/EntityManeger.hpp"
#include <algorithm>

#include "../../include/ECS/baseComponent/Sprite.hpp"
#include "../../include/ECS/baseComponent/Transform.hpp"

Entity* EntityManeger::createEntity(){
  auto entity = std::make_unique<Entity>();
  Entity* rawPtr = entity.get();
  listOfEntities.push_back(std::move(entity));

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

void EntityManeger::Update(){
  for(auto& en : listOfEntities){
    if(en->hasComponent<Transform>() && en->hasComponent<Sprite>()){
      en->getComponent<Sprite>()->sprite.setPosition(
        en->getComponent<Transform>()->x,
        en->getComponent<Transform>()->y
      );
    }
  }
}

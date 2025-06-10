#include <memory>
#include <unordered_map>
#include <typeindex>
#include <SFML/Graphics.hpp>
#include <utility>

#include "Component.hpp"

class Entity{
private:
  std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

public:
  
  template<typename T, typename... Args>
  void addComponent(Args&&... args){
    auto type = std::type_index(typeid(T));
    auto component = std::make_unique<T>(std::forward<Args>(args)...);
    
    components[type] = std::move(component);
  }
 
  template<typename T>
  T* getComponent(){
    auto type = std::type_index(typeid(T));
    if(hasComponent<T>()){
      auto it = components.find(type);

      return static_cast<T*>(it->second.get());
    }
    
    return nullptr;
  }

  template<typename T>
  void removeComponent(){
    if(hasComponent<T>()){
      auto type = std::type_index(typeid(T));
      components.erase(type);
    }
  }

  template<typename T>
  bool hasComponent(){
    auto type = std::type_index(typeid(T));
    return components.find(type) != components.end();
  }
};

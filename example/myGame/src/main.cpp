#include "../../../include/Core/Engine.hpp"
#include "../../../include/Utils/EntityManeger.hpp"

int main(){
  Engine engine(800, 600, "Hello world", 60); 
  EntityManeger em;
  while (engine.gameIsOn()) {
    engine.Run(em);
  }
  return 0;
}

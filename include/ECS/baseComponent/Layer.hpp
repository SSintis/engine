#pragma once

#include "../Component.hpp"

struct Layer : Component{
  int z;

  Layer(int layer) : z(layer) { }
};

namespace Layers {
  const int background = -100;
  const int Object = 0;
  const int GUI = 100;
}

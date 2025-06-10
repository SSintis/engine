#pragma once

#include "../Component.hpp"

struct Transform : public Component{
  int x;
  int y;

  int scale;
};

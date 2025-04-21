
#include "../include/Core/Engine.hpp"
#include "../include/Core/Logger.hpp"
#include <iostream>

int main()
{
    Engine engine(200, 200, "SFML worls!");
    engine.Run();
    return 0;
}
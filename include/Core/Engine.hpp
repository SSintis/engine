#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class Engine{
public:
    Engine();
    Engine(int weight, int height, const std::string& title);
    void Run();

    ~Engine();
private:
    sf::RenderWindow* _window;
};

#endif /* Engine_hpp */
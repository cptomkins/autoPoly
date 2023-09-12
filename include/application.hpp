#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "screen.hpp"

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
    Screen screen;
};

#endif // APPLICATION_HPP
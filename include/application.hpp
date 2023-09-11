#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
};

#endif // APPLICATION_HPP
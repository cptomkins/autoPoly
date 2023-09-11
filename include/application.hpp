#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "screen_manager.hpp"

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
    ScreenManager screenManager; // Create an instance of the screen manager
    // Other members and functions
};

#endif // APPLICATION_HPP
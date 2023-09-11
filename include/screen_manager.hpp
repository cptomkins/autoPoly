#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include "screen.hpp"

class ScreenManager {
public:
    ScreenManager();
    ~ScreenManager();

    void setScreen(Screen* newScreen);
    void handleEvent(sf::Event event);
    void update();
    void render(sf::RenderWindow& window);

private:
    Screen* currentScreen;
    // Add other screens or data members as needed
};

#endif // SCREEN_MANAGER_HPP
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "gui_element.hpp"
#include "background.hpp"

class Screen {
public:
    Screen::Screen(sf::RenderWindow& window);

    virtual void handleEvent(sf::Event event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    // Add other common functionality or data members here if needed
    virtual void createBackground(sf::RenderWindow& window);

private:
    sf::Color backgroundColor; // Store the background color as a member variable
    std::vector<GUIElement> renderVector;
};

#endif // SCREEN_HPP
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "background.hpp"

class Screen {
public:
    Screen(sf::RenderWindow& window);
    ~Screen();
    void handleEvent(sf::Event event);
    void render(sf::RenderWindow& window);
private:
    std::vector<GUIElement*> renderVector;
    Background* background;
};

#endif // SCREEN_HPP
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "background.hpp"
#include "button.hpp"

class Screen {
public:
    Screen(sf::RenderWindow& window);
    ~Screen();
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void render(sf::RenderWindow& window);
private:
    std::vector<GUIElement*> renderVector;
    sf::Font font;
};

#endif // SCREEN_HPP
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "background.hpp"
#include "drum_button.hpp"
#include "label.hpp"

class Screen {
public:
    Screen(sf::RenderWindow& window);
    ~Screen();
    void handleEvent(sf::Event event, sf::RenderWindow &window);
    void render(sf::RenderWindow& window);
    void update();
private:
    std::vector<GUIElement*> renderVector;
    GUIElement* selected;
    sf::Font font;
    Constants constants;
};

#endif // SCREEN_HPP
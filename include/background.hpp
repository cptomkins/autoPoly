#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "gui_element.hpp" // Include the base class header
#include <SFML/Graphics.hpp>

class Background : public GUIElement {
public:
    // Constructor
    Background(sf::Color bgColor, sf::RenderWindow& window);

    virtual void handleEvent(const sf::Event& event);
    virtual void render(sf::RenderWindow& window) const override;

private:
    sf::Color backgroundColor;
    sf::RectangleShape backgroundRect;
};

#endif // BACKGROUND_HPP

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "gui_element.hpp" // Include the base class header
#include <SFML/Graphics.hpp>

class Button : public GUIElement {
public:
    // Constructor
    Button();
    Button(sf::Vector2f boxSize);
    Button(sf::Shape& shape);

    bool isInBounds(sf::Vector2i mousePosition) override;
    void update() override;
    void render(sf::RenderWindow& window) const override;
    void setShape(sf::Shape& shape);
    void setColor(sf::Color color);
    void createText(char Character[], sf::Font& font);

private:
    sf::Color buttonColor;
    sf::Shape* buttonShape;
    sf::Text buttonText;
    bool useText = false;
};

#endif // BACKGROUND_HPP
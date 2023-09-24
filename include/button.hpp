#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "gui_element.hpp"

class Button : public GUIElement {
public:
    // Constructor
    Button();
    Button(sf::Vector2f buttonSize);

    void click() override;
    void setPosition(sf::Vector2f newPosition) override;
    bool isInBounds(sf::Vector2i mousePosition) override;
    sf::Shape& getShape();
    sf::Vector2f& getLocalOffset() override;
    void update() override;
    void render(sf::RenderWindow& window) const override;
    void setShape(sf::Shape& shape);
    void setColor(sf::Color color);
    void createText(char character[], sf::Font& font, unsigned int characterSize = 30, sf::Color textColor = sf::Color::Black);
    void setText(char character[]);
    void positionText(sf::Vector2f textPosition);
    void centerText(bool horizontal = true, bool vertical = true, float extraOffsetX = 0, float extraOffsetY = -8);

protected:
    sf::Color buttonColor;
    sf::Shape* buttonShape;
    sf::Text buttonText;
    sf::Vector2f buttonOffset;
    sf::Vector2f textOffset;
    bool useText = false;
};

#endif // BUTTON_HPP
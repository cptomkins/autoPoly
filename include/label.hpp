#ifndef LABEL_HPP
#define LABEL_HPP

#include "gui_element.hpp" // Include the base class header
#include <SFML/Graphics.hpp>

class Label : public GUIElement {
public:
    // Constructor
    Label();

    void click() override;
    void setPosition(sf::Vector2f newPosition) override;
    sf::Vector2f& getLocalOffset() override;
    void update() override;
    void render(sf::RenderWindow& window) const override;
    void setColor(sf::Color color);
    void createText(char Character[], sf::Font& font);

private:
    sf::Color textColor;
    sf::Text labelText;
    sf::Vector2f labelOffset;
    bool useText = false;
};





#endif // LABEL_HPP
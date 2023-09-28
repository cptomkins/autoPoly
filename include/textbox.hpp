#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "button.hpp"

class Textbox : public Button {
public:
    // Constructor
    Textbox();
    Textbox(sf::Vector2f buttonSize, bool useOutline = true, sf::Color outlineColor = sf::Color::Black);

    void click() override;
    void update() override;
    void handleEvent(sf::Event event, sf::RenderWindow &window) override;
    void render(sf::RenderWindow& window) const override;

private:
    sf::String playerInput;

};

#endif // TEXTBOX_HPP
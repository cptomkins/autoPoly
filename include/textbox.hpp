#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "button.hpp"
#include "constants.hpp"

class Textbox : public Button {
public:
    // Constructor
    Textbox();
    Textbox(sf::Vector2f buttonSize, int characterLimit = 20, bool useOverflow = true, bool useOutline = true, sf::Color outlineColor = sf::Color::Black);

    void click() override;
    void update() override;
    void updateText();
    sf::String getText();
    void deselect() override;
    void inputText(sf::Uint32 character);
    void handleEvent(sf::Event event, sf::RenderWindow &window) override;
    void render(sf::RenderWindow& window) const override;

private:
    sf::String playerInput;
    Constants constants;
    int charLimit;
    bool overflow;
    bool filled = false;
    sf::String defaultText = sf::String("");
};

#endif // TEXTBOX_HPP
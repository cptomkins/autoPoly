#include "textbox.hpp"
#include <iostream>

Textbox::Textbox()
{
}

Textbox::Textbox(sf::Vector2f buttonSize, bool useOutline, sf::Color outlineColor)
{
    buttonShape = new sf::RectangleShape(buttonSize);
    if (useOutline){
        buttonShape->setOutlineThickness(-3);
        buttonShape->setOutlineColor(outlineColor);
    }
}

void Textbox::click()
{
    buttonText.setString(sf::String(""));
}

void Textbox::update()
{
}

void Textbox::render(sf::RenderWindow &window) const
{
    if (buttonShape != NULL){
        window.draw(*buttonShape);
    }
    if (useText){
        window.draw(buttonText);
    }
}

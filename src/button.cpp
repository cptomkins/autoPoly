#include "button.hpp"

Button::Button()
{
    buttonShape = new sf::RectangleShape(sf::Vector2f(150, 50));
}

Button::Button(sf::Vector2f boxSize)
{
    buttonShape = new sf::RectangleShape(boxSize);
}

Button::Button(sf::Shape &shape)
{
    buttonShape = &shape;
}

bool Button::isInBounds(sf::Vector2i mousePosition)
{
    if (buttonShape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        return true;
    }
    return false;
}

void Button::update()
{
}

void Button::render(sf::RenderWindow &window) const
{
    if (buttonShape != NULL){
        window.draw(*buttonShape);
    }
    if (useText){
        window.draw(buttonText);
    }
}

void Button::setShape(sf::Shape &shape)
{
    buttonShape = &shape;
}

void Button::setColor(sf::Color color)
{
    buttonShape->setFillColor(color);
}

void Button::createText(char Character[], sf::Font& font)
{
    buttonText.setFont(font);
    buttonText.setString(Character);
    buttonText.setColor(sf::Color::Black);
    useText = true;
}

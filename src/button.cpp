#include "button.hpp"
#include <iostream>

Button::Button()
{
    buttonShape = new sf::RectangleShape(sf::Vector2f(150, 50));
    if (!buttonBuffer.loadFromFile("C:\\Users\\Cptom\\Desktop\\Bandlab Sounds\\DJA_Snare_05_Snare_BANDLAB.wav"))
    {
        std::cout << "sound not working";
    }
    buttonSound.setBuffer(buttonBuffer);
}

void Button::click()
{
    std::cout << "Button Clicked";
    buttonSound.play();
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

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
    // std::cout << "Button Clicked";
    buttonSound.play();
}

void Button::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
    buttonShape->setPosition(position);
    buttonText.setPosition(position);
}

bool Button::isInBounds(sf::Vector2i mousePosition)
{
    if (buttonShape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        return true;
    }
    return false;
}

sf::Shape &Button::getShape()
{
    return *buttonShape;
}

sf::Vector2f &Button::getLocalOffset()
{
    float widthOffset = static_cast<float>(buttonShape->getLocalBounds().width)/2;
    float heightOffset = static_cast<float>(buttonShape->getLocalBounds().height)/2;
    buttonOffset = sf::Vector2f(widthOffset, heightOffset);
    return buttonOffset;
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

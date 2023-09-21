#include "label.hpp"
#include <iostream>

Label::Label()
{
}

void Label::click()
{
    std::cout << "Label Clicked";
}

void Label::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
    labelText.setPosition(position);
}

sf::Vector2f &Label::getLocalOffset()
{
    float widthOffset = static_cast<float>(labelText.getLocalBounds().width)/2;
    float heightOffset = static_cast<float>(labelText.getLocalBounds().height)/2;
    labelOffset = sf::Vector2f(widthOffset, heightOffset);
    return labelOffset;
}

void Label::update()
{
}

void Label::render(sf::RenderWindow &window) const
{
    if (useText){
        window.draw(labelText);
    }
}

void Label::setColor(sf::Color color)
{
    labelText.setColor(color);
}

void Label::createText(char Character[], sf::Font& font)
{
    labelText.setFont(font);
    labelText.setString(Character);
    useText = true;
}

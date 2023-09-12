#include "screen.hpp"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    backgroundRect.setSize(sf::Vector2f(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)));
    backgroundRect.setFillColor(sf::Color::Blue);
}
void Screen::render(sf::RenderWindow& window){
    window.draw(backgroundRect);
}
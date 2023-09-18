#include "Background.hpp"
#include <iostream>

// Constructor
Background::Background(sf::Color bgColor, sf::RenderWindow& window) : backgroundColor(bgColor) {
    // Initialize backgroundRect with default values
    sf::Vector2u windowSize = window.getSize();
    backgroundRect.setSize(sf::Vector2f(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)));
    backgroundRect.setFillColor(backgroundColor);
}

void Background::click()
{
    std::cout << "Background Clicked";
}

bool Background::isInBounds(sf::Vector2i mousePosition)
{
    if (backgroundRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        return true;
    }
    return false;
}

// Implementation of the render function
void Background::render(sf::RenderWindow& window) const {
    // Implement rendering logic for the background
    window.draw(backgroundRect);
    // You can draw additional elements here if needed
}

sf::Color Background::getBackgroundColor()
{
    return backgroundColor;
}

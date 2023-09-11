#include "Background.hpp"

// Constructor
Background::Background(sf::Color bgColor, sf::RenderWindow& window) : backgroundColor(bgColor) {
    // Initialize backgroundRect with default values
    sf::Vector2u windowSize = window.getSize();
    backgroundRect.setSize(sf::Vector2f(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y)));
    backgroundRect.setFillColor(backgroundColor);
}

// Implementation of the handleEvent function
void Background::handleEvent(const sf::Event& event) {
    // Implement event handling logic for the background if needed
    // For example, you can handle mouse clicks or keyboard input here
}

// Implementation of the render function
void Background::render(sf::RenderWindow& window) const {
    // Implement rendering logic for the background
    window.draw(backgroundRect);
    // You can draw additional elements here if needed
}

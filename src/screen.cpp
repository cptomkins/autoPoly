#include "screen.hpp"

// Implement the constructor for the base screen class
Screen::Screen(sf::RenderWindow& window) : backgroundColor(sf::Color::White) {
    createBackground(window);
}

// Implement the handleEvents function (placeholder)
void Screen::handleEvent(sf::Event event) {
    // Handle events common to all screens here

}

// Implement the update function (placeholder)
void Screen::update() {
    // Update logic common to all screens here

}

// Implement the render function (placeholder)
void Screen::render(sf::RenderWindow& window) {
    for (const GUIElement element : renderVector) {
        element.render(window);
    }
}

// Create a background for the screen
void Screen::createBackground(sf::RenderWindow& window){
    renderVector.push_back(Background(backgroundColor, window));
}
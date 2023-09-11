#include "mainmenu_screen.hpp"

// Implement the constructor for the base screen class
MainMenuScreen::MainMenuScreen(sf::RenderWindow& window) {
    backgroundColor = sf::Color::Black;
    createBackground(window);
}

// Implement the handleEvents function (placeholder)
void MainMenuScreen::handleEvent(sf::Event event) {
    // Handle events common to all screens here

}

// Implement the update function (placeholder)
void MainMenuScreen::update() {
    // Update logic common to all screens here

}
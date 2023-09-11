// ScreenManager.cpp
#include "screen_manager.hpp"

ScreenManager::ScreenManager() : currentScreen(nullptr) {
    // Initialize other members as needed
}

ScreenManager::~ScreenManager() {
    // Clean up screens when the screen manager is destroyed
    if (currentScreen) {
        delete currentScreen;
    }
}

void ScreenManager::setScreen(Screen* newScreen) {
    // Clean up the current screen (if any)
    if (currentScreen) {
        delete currentScreen;
    }

    // Set the new screen
    currentScreen = newScreen;
}

void ScreenManager::handleEvent(sf::Event event) {
    if (currentScreen) {
        currentScreen->handleEvent(event);
    }
}

void ScreenManager::update() {
    if (currentScreen) {
        currentScreen->update();
    }
}

void ScreenManager::render(sf::RenderWindow& window) {
    if (currentScreen) {
        currentScreen->render(window);
    }
}

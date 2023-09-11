// Application.cpp
#include "application.hpp"
#include "mainmenu_screen.hpp"

Application::Application() : window(sf::VideoMode(800, 600), "Auto Poly by CalebFx") {
    // Initialize other members and settings
    screenManager.setScreen(new MainMenuScreen(window)); // Start with the main menu screen
}

void Application::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Pass events to the screen manager
            screenManager.handleEvent(event);
        }

        // Update and render the current screen through the screen manager
        screenManager.update();
        screenManager.render(window);
    }
}

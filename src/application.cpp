// Application.cpp
#include "application.hpp"

Application::Application() : window(sf::VideoMode(800, 600), "Drum Machine by Caleb Tomkins"), screen(window) {
    // Initialize other members and settings
}

void Application::run() {

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            screen.handleEvent(event, window);

        }

        window.clear();

        screen.render(window);

        window.display();

    }
}

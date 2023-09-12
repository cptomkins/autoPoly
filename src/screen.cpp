#include "screen.hpp"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
{
    background = new Background(sf::Color(13, 13, 22), window);
    sf::Vector2u windowSize = window.getSize();
    renderVector.push_back(background);
}
Screen::~Screen()
{
}
void Screen::handleEvent(sf::Event event)
{
}
void Screen::render(sf::RenderWindow &window)
{
    for (GUIElement* element : renderVector) {
        element->render(window);
    }
}
#include "screen.hpp"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    renderVector.push_back(new Background(sf::Color(13, 13, 22), window));

    if(!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")){
        std::cout<<"Font could not load. Perhaps it doesn't exist?";
    }
    char buttonChar[] = "Test Button";

    Button* screenButton = new Button();
    screenButton->createText(buttonChar, font);
    sf::Vector2f newPosition = sf::Vector2f(static_cast<float>(windowSize.x)/2, static_cast<float>(windowSize.y)/2);
    sf::Vector2f buttonOffset = screenButton->getLocalOffset();
    newPosition -= buttonOffset;
    screenButton->setPosition(newPosition);
    renderVector.push_back(screenButton);
}

Screen::~Screen()
{
    for (GUIElement* element : renderVector) {
        delete(element);
    }
}

void Screen::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = renderVector.size() - 1; i >= 0; i--) {
                if(renderVector[i]->isInBounds(sf::Mouse::getPosition(window))){
                    selected = renderVector[i];
                    selected->click();
                    break;
                }
            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            selected->release();
        }
    }
}

void Screen::render(sf::RenderWindow &window)
{
    for (GUIElement* element : renderVector) {
        element->render(window);
    }
}
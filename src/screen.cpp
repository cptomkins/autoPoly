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
            for (GUIElement* element : renderVector) {
                if(element->isInBounds(sf::Mouse::getPosition(window))){
                    std::cout << "HEY MAN GOOD SHIT";
                }
            }
        }
    }
}
void Screen::render(sf::RenderWindow &window)
{
    for (GUIElement* element : renderVector) {
        element->render(window);
    }
}
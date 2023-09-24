#include "screen.hpp"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    renderVector.push_back(new Background(sf::Color(13, 13, 22), window));

    // Font
    if(!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")){
        std::cout<<"Font could not load. Perhaps it doesn't exist?";
    }

    // Button
    sf::Vector2f buttonSize = sf::Vector2f(650, 60);
    DrumButton* screenButton = new DrumButton(buttonSize);
    std::vector<GUIElement*> textBoxes = screenButton->addTextboxes(font);
    sf::Vector2f newPosition = sf::Vector2f(static_cast<float>(windowSize.x)/2, static_cast<float>(windowSize.y)/2);
    sf::Vector2f buttonOffset = screenButton->getLocalOffset();
    newPosition -= buttonOffset;
    screenButton->setPosition(newPosition);
    renderVector.push_back(screenButton);
    renderVector.insert(renderVector.end(), textBoxes.begin(), textBoxes.end());

    // Label
    char labelChar[] = "Enter your sound titles and files below";

    Label* screenLabel = new Label();
    screenLabel->createText(labelChar, font);
    screenLabel->setColor(sf::Color::White);
    newPosition = sf::Vector2f(static_cast<float>(windowSize.x)/2, 30);
    sf::Vector2f labelOffset = sf::Vector2f(screenLabel->getLocalOffset().x, 0-screenLabel->getLocalOffset().y);
    newPosition -= labelOffset;
    screenLabel->setPosition(newPosition);
    renderVector.push_back(screenLabel);
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
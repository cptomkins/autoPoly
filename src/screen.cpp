#include "screen.hpp"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
{
    constants = Constants();
    sf::Vector2u windowSize = window.getSize();
    renderVector.push_back(new Background(sf::Color(13, 13, 22), window));

    selected = renderVector[0];

    // Font
    if(!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")){
        std::cout<<"Font could not load. Perhaps it doesn't exist?";
    }

    // Label
    char labelChar[] = "Enter your sound titles and files below";

    Label* screenLabel = new Label();
    screenLabel->createText(labelChar, font);
    screenLabel->setColor(sf::Color::White);
    sf::Vector2f newPosition = sf::Vector2f(static_cast<float>(windowSize.x)/2, 30);
    sf::Vector2f labelOffset = sf::Vector2f(screenLabel->getLocalOffset().x, 0-screenLabel->getLocalOffset().y);
    newPosition -= labelOffset;
    screenLabel->setPosition(newPosition);
    renderVector.push_back(screenLabel);

    // Button
    createButton(6, sf::Vector2f(650, 60), labelOffset.y, windowSize);
}

Screen::~Screen()
{
    for (GUIElement* element : renderVector) {
        delete(element);
    }
}

void Screen::createButton(int numButtons, sf::Vector2f buttonSize, float verticalOffset, sf::Vector2u windowSize)
{
    sf::Vector2f buttonSize = sf::Vector2f(650, 60);
    DrumButton* drumButton1 = new DrumButton(buttonSize);
    drumButton1->createText("", font);
    drumButton1->centerText(false, true, 5, -15);
    std::vector<GUIElement*> textBoxes = drumButton1->addTextboxes(font);
    sf::Vector2f newPosition = sf::Vector2f(static_cast<float>(windowSize.x)/2, static_cast<float>(windowSize.y)/2);
    sf::Vector2f buttonOffset = drumButton1->getLocalOffset();
    newPosition -= buttonOffset;
    drumButton1->setPosition(newPosition);
    renderVector.push_back(drumButton1);
    renderVector.insert(renderVector.end(), textBoxes.begin(), textBoxes.end());
}

void Screen::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = renderVector.size() - 1; i >= 0; i--) {
                if (renderVector[i] != NULL){
                    if(renderVector[i]->isInBounds(sf::Mouse::getPosition(window))){
                        selected->deselect();
                        selected = renderVector[i];
                        selected->click();
                        break;
                    }
                }
            }
        }
    }

    else if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            selected->release();
        }
    }

    else if (event.type == sf::Event::TextEntered){
        if (event.text.unicode == constants.ENTER){
            selected->deselect();
            selected = renderVector[0];
        }
        else {
            selected->handleEvent(event, window);
        }
    }

    else {
        selected->handleEvent(event, window);
    }
}

void Screen::render(sf::RenderWindow &window)
{
    for (GUIElement* element : renderVector) {
        if (element != NULL){
            element->render(window);
        }
    }
}

void Screen::update()
{
    for (GUIElement* element : renderVector) {
        if (element != NULL){
            element->update();
        }
    }
}

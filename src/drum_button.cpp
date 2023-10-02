#include "drum_button.hpp"
#include <iostream>

DrumButton::DrumButton()
{
}

DrumButton::DrumButton(sf::Vector2f buttonSize)
{
    buttonShape = new sf::RectangleShape(buttonSize);
}

void DrumButton::click()
{
    // std::cout << "Button Clicked";
    
    buttonSound.play();
}

void DrumButton::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
    buttonShape->setPosition(newPosition);
    buttonText.setPosition(textOffset + newPosition);
    if (nameBox != NULL){
        nameBox->setPosition(nameBox->getPosition()+newPosition);
    }
    if (fileBox != NULL){
        fileBox->setPosition(fileBox->getPosition()+newPosition);
    }
}

void DrumButton::setSound(char soundFile[])
{
    if (!buttonBuffer.loadFromFile(soundFile))
    {
        std::cout << "sound not working";
    }
    buttonSound.setBuffer(buttonBuffer);
}

std::vector<GUIElement*> DrumButton::addTextboxes(sf::Font &font, float border)
{
    std::vector<GUIElement*> textBoxes;

    float boxWidth = buttonShape->getLocalBounds().width/2 - (2*border);
    float boxHeight = buttonShape->getLocalBounds().height - (2*border);
    sf::Vector2f nameBoxPosition = sf::Vector2f(0,0);
    sf::Vector2f fileBoxPosition = sf::Vector2f(0,0);
    float positionY = buttonShape->getLocalBounds().height/2;
    float divisionX = buttonShape->getLocalBounds().width/4;
    positionY -= boxHeight/2;
    nameBoxPosition.y = positionY;
    nameBoxPosition.x = divisionX;
    nameBoxPosition.x -= boxWidth/2;
    nameBoxPosition += buttonShape->getPosition();
    fileBoxPosition.y = positionY;
    fileBoxPosition.x = divisionX*3;
    fileBoxPosition.x -= boxWidth/2;
    fileBoxPosition += buttonShape->getPosition();
    
    // Name Box
    nameBox = new Textbox(sf::Vector2f(boxWidth, boxHeight), 24, false);
    nameBox->setPosition(nameBoxPosition);
    char nameText[] = "Name...";
    nameBox->createText(nameText, font, 28, sf::Color(80, 80, 80));
    nameBox->centerText(false, true, 5);

    // File Box
    fileBox = new Textbox(sf::Vector2f(boxWidth, boxHeight), 24);
    fileBox->setPosition(fileBoxPosition);
    char fileText[] = "File...";
    fileBox->createText(fileText, font, 28, sf::Color(80, 80, 80)); 
    fileBox->centerText(false, true, 5);

    textBoxes.push_back(nameBox);
    textBoxes.push_back(fileBox);
    return textBoxes;
}

void DrumButton::update()
{
}

void DrumButton::render(sf::RenderWindow &window) const
{
    if (buttonShape != NULL){
        window.draw(*buttonShape);
    }
    if (useText){
        window.draw(buttonText);
    }
    if (nameBox != NULL){
        nameBox->render(window);
    }
}
#include "drum_button.hpp"
#include <iostream>
#include <fstream>

DrumButton::DrumButton()
{
}

DrumButton::DrumButton(sf::Vector2f buttonSize)
{
    buttonShape = new sf::RectangleShape(buttonSize);
    constants = Constants();
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

void DrumButton::setSound(char soundPath[])
{
    if (!buttonBuffer.loadFromFile(soundPath))
    {
        std::cout << "sound not working";
    }
    buttonSound.setBuffer(buttonBuffer);
}

void DrumButton::transition()
{
    transitioned = true;
    std::cout << "transition";
    nameBox->setSkipRender(true);
    fileBox->setSkipRender(true);
    setSound((char*)soundFileString.toAnsiString().c_str());
    setText((char*)nameBox->getText().toAnsiString().c_str());
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

void DrumButton::validateTransition(){
    if ((nameBox->isFilled()) && (fileBox->isFilled())){
            soundFileString = constants.DEFAULT_DIRECTORY + fileBox->getText();
            std::ifstream soundFile(soundFileString.toAnsiString());
            if (soundFile.good()){
                transition();
            }
            else{
                if(!fileBoxRed){
                    std::cout << soundFileString.toAnsiString();
                    fileBox->setColor(sf::Color(255, 130, 130));
                    fileBoxRed = true;
                }
            }
        }
        else if (fileBoxRed){
            fileBox->setColor(sf::Color::White);
            fileBoxRed = false;
        } 
}

void DrumButton::update()
{
    if (!transitioned){
        validateTransition();
    }
}

void DrumButton::render(sf::RenderWindow &window) const
{
    if (buttonShape != NULL){
        window.draw(*buttonShape);
    }
    if (useText){
        window.draw(buttonText);
    }
}
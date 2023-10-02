#include "textbox.hpp"
#include <iostream>

Textbox::Textbox()
{
    constants = Constants();
}

Textbox::Textbox(sf::Vector2f buttonSize, int characterLimit, bool useOverflow, bool useOutline, sf::Color outlineColor)
{
    overflow = useOverflow;
    charLimit = characterLimit;
    buttonShape = new sf::RectangleShape(buttonSize);
    if (useOutline){
        buttonShape->setOutlineThickness(-3);
        buttonShape->setOutlineColor(outlineColor);
    }
    constants = Constants();
}

void Textbox::click()
{
    if (defaultText.getSize() == 0){
        defaultText = buttonText.getString();
    }
    updateText();
}

void Textbox::update()
{
}

void Textbox::updateText(){
    if (playerInput.getSize() <= charLimit){
        buttonText.setString(playerInput);
    }
    else {
        buttonText.setString(playerInput.substring(playerInput.getSize()-charLimit, charLimit));
    }
}

sf::String Textbox::getText()
{
    return playerInput;
}

void Textbox::deselect()
{
    if (playerInput.getSize() > 0){
        filled = true;
    }
    else{
        buttonText.setString(defaultText);
    }
}

void Textbox::inputText(sf::Uint32 character)
{
    if (character == constants.BACKSPACE){
        if (playerInput.getSize() > 0){
            playerInput.erase(playerInput.getSize()-1);
            updateText();
        }
    }
    else if (character == constants.PASTE){
        std::cout << "Paste not implemented";
    }
    else {
        if (playerInput.getSize() < charLimit){
            playerInput += character;
            updateText();
        }
        else if (overflow){
            playerInput += character;
            updateText();
        }
    }
}

void Textbox::handleEvent(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::TextEntered)
    {
        inputText(event.text.unicode);
    }
}

void Textbox::render(sf::RenderWindow &window) const
{
    if (buttonShape != NULL){
        window.draw(*buttonShape);
    }
    if (useText){
        window.draw(buttonText);
    }
}

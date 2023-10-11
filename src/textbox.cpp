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

Textbox::~Textbox()
{
    delete(buttonShape);
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

bool Textbox::isFilled()
{
    return filled;
}

void Textbox::deselect()
{
    if (playerInput.getSize() > 0){
        filled = true;
    }
    else{
        buttonText.setString(defaultText);
        filled = false;
    }
}

bool Textbox::isInBounds(sf::Vector2i mousePosition)
{
    if (_skipRender){
        return false;
    }
    if (buttonShape->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        return true;
    }
    return false;
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

void Textbox::setSkipRender(bool skipRender)
{
    _skipRender = skipRender;
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
    if (!_skipRender){
        if (buttonShape != NULL){
            window.draw(*buttonShape);
        }
        if (useText){
            window.draw(buttonText);
        }
    }
}

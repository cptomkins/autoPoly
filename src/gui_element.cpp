#include "gui_element.hpp"

// Constructor
GUIElement::GUIElement() {
    // Initialize any member variables here if needed
}

// Destructor (virtual to allow for proper destruction in derived classes)
GUIElement::~GUIElement() {
    // Perform any necessary cleanup here
}

void GUIElement::click()
{
}

void GUIElement::release()
{
}

void GUIElement::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

bool GUIElement::isInBounds(sf::Vector2i mousePosition)
{
    return false;
}

sf::Vector2f &GUIElement::getLocalOffset()
{
    return localOffset;
}

// Placeholder implementation for update() function
void GUIElement::update() {
    // Implement update logic for your GUI element
}

// Placeholder implementation for render() function
void GUIElement::render(sf::RenderWindow& window) const {
    // Implement rendering logic for your GUI element
    // You can use the 'window' object to draw elements on the screen
    // For example, you can draw shapes, text, or sprites here
}
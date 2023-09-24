#ifndef GUIELEMENT_HPP
#define GUIELEMENT_HPP

#include <SFML/Graphics.hpp>

class GUIElement {
public:
    // Constructor
    GUIElement();

    // Destructor (virtual to allow for proper destruction in derived classes)
    virtual ~GUIElement();

    // Public member functions for interaction and rendering
    virtual void click();
    virtual void release();
    virtual void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition();
    virtual bool isInBounds(sf::Vector2i mousePosition);
    virtual sf::Vector2f& getLocalOffset();
    virtual void update();
    virtual void render(sf::RenderWindow& window) const;

    // Getters and setters (as needed)

protected:
    // Private member variables (as needed)
    sf::Vector2f position;
    sf::Vector2f localOffset;
};

#endif // GUIELEMENT_HPP
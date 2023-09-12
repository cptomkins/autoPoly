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
    virtual void handleEvent(const sf::Event& event);
    virtual void update();
    virtual void render(sf::RenderWindow& window) const;

    // Getters and setters (as needed)

private:
    // Private member variables (as needed)
};

#endif // GUIELEMENT_HPP
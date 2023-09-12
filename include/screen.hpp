#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
private:
    sf::RectangleShape backgroundRect;
};

#endif // SCREEN_HPP
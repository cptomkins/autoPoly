#ifndef MAINMENU_SCREEN_HPP
#define MAINMENU_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "gui_element.hpp"
#include "background.hpp"
#include "screen.hpp"

class MainMenuScreen : public Screen {
public:
    MainMenuScreen(sf::RenderWindow& window);

    void handleEvent(sf::Event event);
    void update();

};

#endif // MAINMENU_SCREEN_HPP
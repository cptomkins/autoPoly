#ifndef DRUM_BUTTON_HPP
#define DRUM_BUTTON_HPP

#include "button.hpp"
#include "textbox.hpp"
#include "constants.hpp"
#include <SFML/Audio.hpp>

class DrumButton : public Button {
public:
    // Constructor
    DrumButton();
    DrumButton(sf::Vector2f buttonSize);

    void click() override;
    void setPosition(sf::Vector2f newPosition) override;
    void setSound(char soundPath[]);
    void transition();
    std::vector<GUIElement*> addTextboxes(sf::Font& font, float border=5);
    void validateTransition();
    void update() override;
    void render(sf::RenderWindow& window) const override;

private:
    sf::String soundFileString;
    sf::SoundBuffer buttonBuffer;
    sf::Sound buttonSound;
    Textbox* nameBox;
    Textbox* fileBox;
    bool fileBoxRed = false;
    bool transitioned = false;
    Constants constants;
};

#endif // BUTTON_HPP
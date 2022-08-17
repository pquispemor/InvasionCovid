#pragma once
#ifndef VICTORIA_H
#define VICTORIA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Victoria : public sf::Drawable
{
private:
    //Texto
    sf::Font fontResultado;
    sf::Text VictoriaText;
    sf::Text VictoriaAux;
    //Audio
    sf::SoundBuffer winner;
    sf::Sound sound_win;

    void iniciarText();
    void iniciarAudio();
public:

    Victoria(/* args */);
    ~Victoria() {};
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
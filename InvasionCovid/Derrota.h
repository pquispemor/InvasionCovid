#pragma once
#ifndef DERROTA_H
#define DERROTA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Derrota : public sf::Drawable
{
private:
    //Texto
    sf::Font fontResultado;
    sf::Text DerrotaText;
    sf::Text DerrotaAux;

    //Audio
    sf::SoundBuffer loser;
    sf::Sound sound_loser;

    void iniciarText();
    void iniciarAudio();
public:

    Derrota(/* args */);
    ~Derrota() {};
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif



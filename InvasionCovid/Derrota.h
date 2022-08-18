#pragma once
#ifndef DERROTA_H
#define DERROTA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Derrota : public sf::Drawable
{
private:
    //Sprite
    sf::Sprite derrota;
    sf::Texture derrotaTexture;

    //Audio
    sf::SoundBuffer loser;
    sf::Sound sound_loser;

    void iniciarGUI();
    void iniciarAudio();
public:

    Derrota(/* args */);
    ~Derrota() {};
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif



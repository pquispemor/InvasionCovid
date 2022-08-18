#pragma once
#ifndef VICTORIA_H
#define VICTORIA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Victoria : public sf::Drawable
{
private:
    //Sprite
    sf::Sprite victoria;
    sf::Texture victoriaTexture;
    //Audio
    sf::SoundBuffer winner;
    sf::Sound sound_win;

    void iniciarGUI();
    void iniciarAudio();
public:

    Victoria(/* args */);
    ~Victoria() {};
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
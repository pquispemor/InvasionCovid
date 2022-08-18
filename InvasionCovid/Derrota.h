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

    //Functor
    void operator()(std::string v) {
        std::cout << "----------" << v << "----------\n";
    }
    Derrota(/* args */);
    ~Derrota() {};
    //Patron de Diseño Singleton
    static Derrota* get_derrota();
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif



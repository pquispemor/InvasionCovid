#pragma once
#ifndef VICTORIA_H
#define VICTORIA_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

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
    //Functor
    void operator()(std::string v) {
        std::cout << "----------" << v << "----------\n";
    }
    Victoria(/* args */);
    ~Victoria() {};
    //Patron de Diseño Singleton
    static Victoria* get_victoria();
    void sonido();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
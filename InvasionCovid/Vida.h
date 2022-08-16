#pragma once
#ifndef VIDA_H
#define VIDA_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Vida : public sf::Drawable
{
private:
    sf::Sprite spriteVida;
    sf::Texture textureVida;
    void iniciarForma();
public:
    Vida(float pos_x, float pos_y);
    ~Vida();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif


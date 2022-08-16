#pragma once
#ifndef BALA_H
#define BALA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bala : public sf::Drawable
{
private:
    sf::Sprite shape;

    sf::Vector2f direccion;
    float moveSpeed;

public:
    Bala();
    Bala(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed);
    ~Bala();

    //*Accesorio
    const sf::FloatRect getLimites() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
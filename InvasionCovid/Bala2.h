#pragma once
#ifndef BALA2_H
#define BALA2_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bala2 : public sf::Drawable
{
private:
    sf::Sprite shape;

    sf::Vector2f direccion;
    float moveSpeed;
public:
    Bala2();
    Bala2(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed);
    ~Bala2();

    //*Accesorio
    const sf::FloatRect getLimites() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

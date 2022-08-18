#pragma once
#ifndef JUGADORMAIN_H
#define JUGADORMAIN_H

#include <SFML/Graphics.hpp>
#include <iostream>

class JugadorMain : public sf::Drawable
{
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    float moveSpeed;

    float ataqueTiempo;
    float ataqueTiempoMax;

    int danio;
    int hp;


    void iniciarVariables();


public:
    JugadorMain();
    ~JugadorMain();

    virtual void IniciarSpriteYPos();

    //*Accesorio
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getLimites() const;

    //*Modificadores
    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);

    //*Funciones

    void move(const float dirX, const float dirY);
    const bool puedesAtacar();

    void updateAtaque();
    void updateCollision();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    friend std::ostream& operator<<(std::ostream& out, const JugadorMain& p);
};

#endif

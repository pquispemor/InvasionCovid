#pragma once
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML\Graphics.hpp>

class Enemigo : public sf::Drawable
{
private:
    unsigned conteoPuntos;
    sf::Sprite sprite;
    sf::Texture texture;
    int tipo;
    float velocidad;
    int hp;
    int hpMax;
    int danio;
    int puntos;

    void iniciarVariables();
    void iniciarForma();

public:
    Enemigo(float pos_x, float pos_y);
    ~Enemigo();

    //*Accesorio
    const sf::FloatRect getLimites() const;
    const int& getPuntos() const;

    void setTipo(int);
    void setTexture(sf::Texture texture);
    void setVelocidad(float velocidad);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    friend std::ostream& operator<<(std::ostream& out, const Enemigo& p);
};

#endif


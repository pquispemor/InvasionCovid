#pragma once
#ifndef MINIONETAPA1_H
#define MINIONETAPA1_H

#include <SFML\Graphics.hpp>

class MinionEtapa1 : public sf::Drawable
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
    MinionEtapa1(float pos_x, float pos_y);
    ~MinionEtapa1();

    //*Accesorio
    const sf::FloatRect getLimites() const;
    const int& getPuntos() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    friend std::ostream& operator<<(std::ostream& out, const MinionEtapa1& p);
};

#endif


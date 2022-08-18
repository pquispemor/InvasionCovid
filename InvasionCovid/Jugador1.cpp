#include "Jugador1.h"

Jugador1::Jugador1()
{
    this->iniciarVariables();
    this->IniciarSpriteYPos();
}

Jugador1::~Jugador1()
{
}

void Jugador1::IniciarSpriteYPos()
{
    this->texture.loadFromFile("Sprites\\Player1.png");
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.8f, 0.8f);
    this->sprite.setPosition(sf::Vector2f(350 - sprite.getGlobalBounds().width, 600 - sprite.getGlobalBounds().height));
}


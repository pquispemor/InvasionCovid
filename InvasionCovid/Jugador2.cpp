#include "Jugador2.h"

Jugador2::Jugador2()
{
    this->iniciarVariables();
    this->IniciarSpriteYPos();
}

Jugador2::~Jugador2()
{
}

void Jugador2::IniciarSpriteYPos()
{
    this->texture.loadFromFile("Sprites\\Player2.png");
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.8f, 0.8f);
    this->sprite.setPosition(sf::Vector2f(550 - sprite.getGlobalBounds().width, 600 - sprite.getGlobalBounds().height));
}
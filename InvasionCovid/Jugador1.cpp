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

std::ostream& operator<<(std::ostream& out, const Jugador1& p)
{
    
    out << "\n\tDATOS DEL JUGADOR\n";
    out << "Jugador : " << p.tipo << std::endl;
    out << "Vida del Jugador : " << p.hp << std::endl;
    out << "Danio del Jugador : " << p.danio << std::endl;
    out << "Velocidad del Jugador : " << p.moveSpeed << std::endl;

    return out;
}

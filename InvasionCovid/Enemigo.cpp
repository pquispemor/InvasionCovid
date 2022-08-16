#include "Enemigo.h"

void Enemigo::iniciarVariables() {
    this->tipo = 1;
    this->velocidad = 5.f;
    this->hpMax = 10;
    this->hp = 0;
    this->danio = 1;
    this->puntos = 50;
}

void Enemigo::iniciarForma() {
    this->texture.loadFromFile("Sprites\\Minion1.png");
    this->sprite.setTexture(this->texture);
}

Enemigo::Enemigo(float pos_x, float pos_y)
{
    this->iniciarForma();
    this->iniciarVariables();

    this->sprite.setPosition(pos_x, pos_y);

}

Enemigo::~Enemigo()
{
}


const sf::FloatRect Enemigo::getLimites() const {
    return this->sprite.getGlobalBounds();
}

const int& Enemigo::getPuntos() const {
    return this->puntos;
}

void Enemigo::update() {
    this->sprite.move(0.f, this->velocidad);
}

void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->sprite, states);
}

std::ostream& operator<<(std::ostream& out, const Enemigo& p)
{
    // TODO: Insertar una instrucci�n "return" aqu�
    out << "\n\tDATOS DEL ENEMIGO\n";
    out << "Tipo del Enemigo : " << p.tipo;
    out << "Velocidad del Enemigo : " << p.velocidad;
    out << "Vida del Enemgio : " << p.hpMax;
    out << "Da�o del Enemigo : " << p.danio;
    out << "Puntos que otorga el Enemigo : " << p.puntos;

    return out;
}

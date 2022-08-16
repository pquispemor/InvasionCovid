#include "MinionEtapa1.h"

void MinionEtapa1::iniciarVariables() {
    this->conteoPuntos = 50;
    this->tipo = 0;
    this->velocidad = 5.f;
    this->hpMax = 10;
    this->hp = 0;
    this->danio = 1;
    this->puntos = 50;
}

void MinionEtapa1::iniciarForma() {
    this->texture.loadFromFile("Sprites\\Minion1.png");
    this->sprite.setTexture(this->texture);
}

MinionEtapa1::MinionEtapa1(float pos_x, float pos_y)
{
    this->iniciarForma();
    this->iniciarVariables();

    this->sprite.setPosition(pos_x, pos_y);

}

MinionEtapa1::~MinionEtapa1()
{
}


const sf::FloatRect MinionEtapa1::getLimites() const {
    return this->sprite.getGlobalBounds();
}

const int& MinionEtapa1::getPuntos() const {
    return this->puntos;
}

void MinionEtapa1::update() {
    this->sprite.move(0.f, this->velocidad);
}

void MinionEtapa1::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->sprite, states);
}

std::ostream& operator<<(std::ostream& out, const MinionEtapa1& p)
{
    // TODO: Insertar una instrucción "return" aquí
    out << "\n\tDATOS DEL ENEMIGO\n";
    out << "Tipo del Enemigo : " << p.tipo << std::endl;
    out << "Velocidad del Enemigo : " << p.velocidad << std::endl;
    out << "Vida del Enemgio : " << p.hpMax << std::endl;
    out << "Danio del Enemigo : " << p.danio << std::endl;
    out << "Puntos que otorga el Enemigo : " << p.puntos << std::endl;

    return out;
}

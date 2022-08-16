#include "Bala.h"

Bala::Bala() {}

Bala::Bala(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed)
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(pos_x - 5, pos_y - 30);
    this->direccion.x = dir_x;
    this->direccion.y = dir_y;
    this->moveSpeed = moveSpeed;
}

Bala::~Bala()
{
}

const sf::FloatRect Bala::getLimites() const {
    return this->shape.getGlobalBounds();
}

void Bala::update() {
    //* Movimiento de la bala
    this->shape.move(this->moveSpeed * this->direccion);
}

void Bala::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->shape, states);
}
#include "Bala2.h"
Bala2::Bala2() {}

Bala2::Bala2(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed)
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(pos_x +5, pos_y +30);
    this->direccion.x = dir_x;
    this->direccion.y = dir_y;
    this->moveSpeed = moveSpeed;
}

Bala2::~Bala2()
{
}

const sf::FloatRect Bala2::getLimites() const {
    return this->shape.getGlobalBounds();
}

void Bala2::update() {
    //* Movimiento de la bala
    this->shape.move(this->moveSpeed * this->direccion);
}

void Bala2::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->shape, states);
}
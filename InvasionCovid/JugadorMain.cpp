#include "JugadorMain.h"
void JugadorMain::iniciarVariables() {
    this->moveSpeed = 6.f;

    this->ataqueTiempoMax = 10.f;
    this->ataqueTiempo = this->ataqueTiempoMax;

    this->danio = 10;
    this->hp = 3;

}


JugadorMain::JugadorMain(/* args */)
{
    this->iniciarVariables();
    this->IniciarSpriteYPos();
}

JugadorMain::~JugadorMain()
{
}

void JugadorMain::IniciarSpriteYPos()
{
}

const sf::Vector2f& JugadorMain::getPos() const {
    return this->sprite.getPosition();
}

const sf::FloatRect JugadorMain::getLimites() const {
    return this->sprite.getGlobalBounds();
}

void JugadorMain::setPosition(const sf::Vector2f pos) {
    this->sprite.setPosition(pos);
}

void JugadorMain::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void JugadorMain::move(const float dirX, const float dirY) {
    this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

const bool JugadorMain::puedesAtacar() {
    if (this->ataqueTiempo >= this->ataqueTiempoMax) {
        this->ataqueTiempo = 0.f;
        return true;
    }
    return false;
}

void JugadorMain::updateAtaque() {

    if (this->ataqueTiempo < this->ataqueTiempoMax)
        this->ataqueTiempo += 0.5f;
}

void JugadorMain::update() {
    this->updateAtaque();
}

void JugadorMain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->sprite, states);
}
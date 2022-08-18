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

void JugadorMain::updateCollision()
{
    if (sprite.getPosition().x < 0) {
        sprite.setPosition(0, sprite.getPosition().y);
    }

    if (sprite.getPosition().y < 0) {
        sprite.setPosition(sprite.getPosition().x, 0);
    }

    if (sprite.getPosition().x + sprite.getGlobalBounds().width > 800) {
        sprite.setPosition(800 - sprite.getGlobalBounds().width, sprite.getPosition().y);
    }

    if (sprite.getPosition().y + sprite.getGlobalBounds().height > 600) {
        sprite.setPosition(sprite.getPosition().x, 600 - sprite.getGlobalBounds().height);
    }
}

void JugadorMain::update() {
    this->updateAtaque();
    this->updateCollision();
}

void JugadorMain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->sprite, states);
}

std::ostream& operator<<(std::ostream& out, const JugadorMain& p)
{

    out << "\n\tDATOS DEL JUGADOR\n";
    out << "Vida del Jugador : " << p.hp << std::endl;
    out << "Danio del Jugador : " << p.danio << std::endl;
    out << "Velocidad del Jugador : " << p.moveSpeed << std::endl;

    return out;
}
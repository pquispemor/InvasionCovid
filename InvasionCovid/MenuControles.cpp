#include "MenuControles.h"

void MenuControles::iniciarSprite()
{
	this->textura.loadFromFile("Fondos\\MenuControles.png");
	this->fondo.setTexture(this->textura);
}

MenuControles::MenuControles()
{
	this->iniciarSprite();
}

MenuControles::~MenuControles()
{
}

void MenuControles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->fondo, states);
}
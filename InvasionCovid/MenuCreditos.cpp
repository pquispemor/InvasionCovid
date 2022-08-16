#include "MenuCreditos.h"

void MenuCreditos::iniciarSprite()
{
	this->textura.loadFromFile("Fondos\\MenuCreditos.png");
	this->fondo.setTexture(this->textura);
}

MenuCreditos::MenuCreditos()
{
	this->iniciarSprite();
}

MenuCreditos::~MenuCreditos()
{
}

void MenuCreditos::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->fondo, states);
}

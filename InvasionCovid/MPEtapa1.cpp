#include "MPEtapa1.h"


void MPEtapa1::iniciarInterfaz()
{
	this->texture.loadFromFile("Fondos\\Fase1.png");
	fondo.setTexture(this->texture);
}

MPEtapa1::MPEtapa1()
{
	this->iniciarInterfaz();
}

MPEtapa1::~MPEtapa1()
{
}

void MPEtapa1::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->fondo, states);
}

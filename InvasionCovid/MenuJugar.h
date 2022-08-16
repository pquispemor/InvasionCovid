#pragma once
#ifndef MENUJUGAR_H
#define MENUJUGAR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

class MenuJugar : public sf::Drawable
{
private:
	//Sprite
	sf::Sprite fondo;
	sf::Texture textura;
	int MenuJugarSeleccion;
	sf::Font font;
	sf::Text MenuJugarText[2];

	void iniciarSprite();
public:
	MenuJugar();
	~MenuJugar();
	void MoverArriba();
	void MoverAbajo();
	int MenuJugarPressed();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

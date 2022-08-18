#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Menu : public sf::Drawable
{
protected:
	int MenuJugarSeleccion;
	sf::Font font;
	sf::Text MenuJugarText[2];
	//Sprite
	sf::Sprite fondo;
	sf::Texture textura;

	virtual void iniciarSprite() {};
public:
	Menu();
	~Menu();
	virtual void MoverArriba() {};
	virtual void MoverAbajo() {};
	int MenuJugarPressed();
	virtual void draw() {};
};

#endif

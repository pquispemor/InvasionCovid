#pragma once
#ifndef MENUCONTROLES_H
#define MENUCONTROLES_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class MenuControles : public sf::Drawable
{
private:
	//Sprite
	sf::Sprite fondo;
	sf::Texture textura;

	void iniciarSprite();
public:
	MenuControles();
	~MenuControles();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

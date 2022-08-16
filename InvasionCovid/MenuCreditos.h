#pragma once
#ifndef MENUCREDITOS_H
#define MENUCREDITOS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class MenuCreditos : public sf::Drawable
{
private:
	//Sprite
	sf::Sprite fondo;
	sf::Texture textura;

	void iniciarSprite();
public:
	MenuCreditos();
	~MenuCreditos();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
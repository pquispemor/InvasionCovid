#pragma once
#ifndef MENUCONTROLES_H
#define MENUCONTROLES_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Menu.h"
class MenuControles : public Menu
{
private:

	void iniciarSprite();
public:
	MenuControles();
	~MenuControles();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

#pragma once
#ifndef MENUCREDITOS_H
#define MENUCREDITOS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Menu.h"

class MenuCreditos : public Menu
{
private:
	void iniciarSprite();
public:
	MenuCreditos();
	~MenuCreditos();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
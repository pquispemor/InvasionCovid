#pragma once
#ifndef MENUJUGAR_H
#define MENUJUGAR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Menu.h"

class MenuJugar : public Menu
{
private:
	void iniciarSprite();
public:
	MenuJugar();
	~MenuJugar();
	void MoverArriba();
	void MoverAbajo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

#pragma once
#include "Menu.h"
#include "MenuJugar.h"
#include "MenuControles.h"
#include "MenuCreditos.h"
class MenuFactory
{
private:
	Menu* menu;
public:
	Menu* getMenu(int opcion);
};

#include "MenuFactory.h"

Menu* MenuFactory::getMenu(int opcion)
{
	switch (opcion) {
	case 1:
		menu = new MenuJugar;
		break;
	case 2:
		menu = new MenuControles;
		break;
	case 3:
		menu = new MenuCreditos;
		break;
	}

	return menu;
}

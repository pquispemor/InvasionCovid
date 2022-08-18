#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "MainMenuExtras.h"
#include "MenuJugar.h"
#include "MenuControles.h"
#include "MenuCreditos.h"
#include "MenuFactory.h"
#include "Menu.h"
#include "SP_Etapa1.h"
#include <memory>


class MainMenu
{
private:
	//Ventana
	std::shared_ptr<sf::RenderWindow> window;
	int anchura = 800;
	int altura = 600;
	int fps = 60;

	//Evento
	sf::Event event;

	//Sprite
	sf::Sprite fondo;
	sf::Texture textura;

	//Audio
	sf::SoundBuffer audio;
	sf::Sound sound;

	//Audio Extras
	sf::SoundBuffer audioMover;
	sf::Sound sound_Mover;
	sf::SoundBuffer audioSeleccion;
	sf::Sound sound_Seleccion;
	sf::SoundBuffer audioEscape;
	sf::Sound sound_Escape;
	int s1 = 0;


	//MainMenuExtras
	MainMenuExtras mainMenuExtras;

	//MainMenu Otras Ventanas
	int y = 0;
	MenuFactory menuFactory;
	Menu* menuSeleccionado;

	//MenuJugar Otras ventanas
	int SeleccionJugar = 0;


	//Inicializaciones
	void iniciarWindow();
	void iniciarSprite();
	void iniciarAudio();

public:
	MainMenu();
	~MainMenu();

	void updatePollEvent();
	void updateEntrada();
	void update();
	void render();
	void run();
};

#endif // MAINMENU_H

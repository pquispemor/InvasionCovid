#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Window.h"
#include "MainMenuExtras.h"
#include "MenuJugar.h"
#include "MenuControles.h"
#include "MenuCreditos.h"
#include "SP_Etapa1.h"
#include "MultiplayerJuego.h"



class MainMenu : public Window
{
private:
	//Ventana
	sf::RenderWindow* window;

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
	sf::SoundBuffer audioSpace;
	sf::Sound sound_Space;
	sf::SoundBuffer audioEscape;
	sf::Sound sound_Escape;


	//MainMenuExtras
	MainMenuExtras mainMenuExtras;

	//MainMenu Otras Ventanas
	int y = 0;
	MenuJugar menuJugar;
	MenuControles menuControles;
	MenuCreditos menuCreditos;

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

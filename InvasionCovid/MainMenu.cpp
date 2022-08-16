#include "MainMenu.h"

void MainMenu::iniciarWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(anchura,altura), "Invasion Covid");
	this->window->setFramerateLimit(60); //60 fps
}

void MainMenu::iniciarSprite()
{
	this->textura.loadFromFile("Fondos\\Menu.png");
	this->fondo.setTexture(this->textura);
}

void MainMenu::iniciarAudio()
{	
	//Escenario
	this->audio.loadFromFile("Audio\\AudioMainMenu\\MainMenu.ogg");
	this->sound.setBuffer(audio);
	this->sound.setLoop(true);
	this->sound.setVolume(30);

	//Extras
	this->audioMover.loadFromFile("Audio\\AudioMainMenu\\Mover.ogg");
	this->sound_Mover.setBuffer(audioMover);

	this->audioSpace.loadFromFile("Audio\\AudioMainMenu\\SpacePush.ogg");
	this->sound_Space.setBuffer(audioSpace);

	this->audioEscape.loadFromFile("Audio\\AudioMainMenu\\EscapePush.ogg");
	this->sound_Escape.setBuffer(audioEscape);

}

MainMenu::MainMenu()
{
	this->iniciarWindow();
	this->iniciarSprite();
	this->iniciarAudio();
	sound.play();
}

MainMenu::~MainMenu()
{
	delete this->window;
}

void MainMenu::updateEntrada()
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::W) {
			if (y == 0) {
				mainMenuExtras.MoverArriba();
				sound_Mover.play();
			}
			else {
				menuJugar.MoverArriba();
			}
		}

		if (event.key.code == sf::Keyboard::S) {
			if (y == 0) {
				mainMenuExtras.MoverAbajo();
				sound_Mover.play();
			}
			else {
				menuJugar.MoverAbajo();
			}
		}

		if (event.key.code == sf::Keyboard::Space) {
			sound_Space.play();
			if (y == 0) {
				int mainMenuOpcion = mainMenuExtras.MainMenuPressed();
				switch (mainMenuOpcion)
				{
				case 0:
					y = 1;
					break;
				case 1:
					y = 2;
					break;
				case 2:
					y = 3;
					break;
				case 3:
					window->close();
					break;
				}
			}
			else {
				int menuJugarOpcion = menuJugar.MenuJugarPressed();
				//Un Jugador
				if (menuJugarOpcion >= 0)
					sound.stop();
				else
					sound.play();
				if (menuJugarOpcion == 0) {
					SP_Etapa1 sp_etapa1;
					sp_etapa1.run();
				}
				if (menuJugarOpcion == 1) {
					MultiplayerJuego mp_juego;
					mp_juego.run();

				}
			}
			
		}
	}
}


void MainMenu::updatePollEvent()
{
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape) {
			if (y > 0) {
				sound_Escape.play();
				y = 0;
			}
		}
		this->updateEntrada();
	}
}

//Actualizacion
void MainMenu::update()
{
	this->updatePollEvent();

}

//Dibujo
void MainMenu::render()
{
	this->window->clear();
	if (y == 0) {
		//Dibujo MainMenu
		this->window->draw(fondo);
		//Dibujando MainMenuExtras
		this->window->draw(mainMenuExtras);
	}
	else if (y == 1) {
		this->window->draw(menuJugar);
	}
	else if (y == 2) {
		this->window->draw(menuControles);
	}
	else if (y == 3) {
		this->window->draw(menuCreditos);
	}

	this->window->display();
}

//Correr
void MainMenu::run()
{
	while (this->window->isOpen()) {

		//Actualizacion
		this->update();
		//Dibujo
		this->render();
	}
}
#include "MainMenu.h"

void MainMenu::iniciarWindow()
{
	std::shared_ptr<sf::RenderWindow> p(new sf::RenderWindow(sf::VideoMode(anchura, altura), "Invasion Covid"));
	this->window = p;
	this->window->setFramerateLimit(fps); //60 fps
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

	this->audioSeleccion.loadFromFile("Audio\\AudioMainMenu\\SpacePush.ogg");
	this->sound_Seleccion.setBuffer(audioSeleccion);

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
	//delete this->window;
}

void MainMenu::updateEntrada()
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::W) {
			if (y == 0) {
				mainMenuExtras.MoverArriba();
				sound_Mover.play();
			}
			if (y == 1){
				menuSeleccionado->MoverArriba();
				sound_Mover.play();
			}
		}

		if (event.key.code == sf::Keyboard::S) {
			if (y == 0) {
				mainMenuExtras.MoverAbajo();
				sound_Mover.play();
			}
			if (y == 1) {
				menuSeleccionado->MoverAbajo();
				sound_Mover.play();
			}
		}

		if (event.key.code == sf::Keyboard::Space) {
			sound_Seleccion.play();
			if (y == 0) {
				int mainMenuOpcion = mainMenuExtras.MainMenuPressed();
				switch (mainMenuOpcion)
				{
				case 0:
					y = 1;
					menuSeleccionado = menuFactory.getMenu(y);
					break;
				case 1:
					y = 2;
					menuSeleccionado = menuFactory.getMenu(y);
					break;
				case 2:
					y = 3;
					menuSeleccionado = menuFactory.getMenu(y);
					break;
				case 3:
					window->close();
					break;
				}
			}
			else {
				int menuJugarOpcion = menuSeleccionado->MenuJugarPressed();
				//Un Jugador
				if (menuJugarOpcion == 0) {
					if (s1 == 0) {
						sound.stop();
						s1 = 1;
					}
					SP_Etapa1 sp_etapa1;
					sp_etapa1.run();

				}
				else if (menuJugarOpcion == 1) {

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
				if (s1 == 1) {
					sound.play();
					s1 = 0;
				}
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
		this->window->draw(*this->menuSeleccionado);
	}
	else if (y == 2) {
		this->window->draw(*this->menuSeleccionado);
	}
	else if (y == 3) {
		this->window->draw(*this->menuSeleccionado);
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
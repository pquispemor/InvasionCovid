#include "MainMenuExtras.h"

void MainMenuExtras::iniciarExtras()
{
    if (!font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    int tamsize = 50;
    //*Jugar
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Jugar");
    mainMenu[0].setCharacterSize(tamsize);
    mainMenu[0].setPosition(340, 250);
    //*Controles
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Controles");
    mainMenu[1].setCharacterSize(tamsize);
    mainMenu[1].setPosition(300, 320);
    //*Creditos;
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("Creditos");
    mainMenu[2].setCharacterSize(tamsize);
    mainMenu[2].setPosition(320, 390);
    //*Salir
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Salir");
    mainMenu[3].setCharacterSize(tamsize);
    mainMenu[3].setPosition(350, 460);
    MainMenuSeleccion = 0;
    mainMenu[MainMenuSeleccion].setFillColor(sf::Color::Blue);
}

MainMenuExtras::MainMenuExtras()
{
    this->iniciarExtras();
}

MainMenuExtras::~MainMenuExtras()
{
}

void MainMenuExtras::MoverArriba()
{
    if (MainMenuSeleccion - 1 >= 0) {
        mainMenu[MainMenuSeleccion].setFillColor(sf::Color::White);
        MainMenuSeleccion--;
        if (MainMenuSeleccion == -1) {
            MainMenuSeleccion = 2;
        }
        mainMenu[MainMenuSeleccion].setFillColor(sf::Color::Blue);
    }
}

void MainMenuExtras::MoverAbajo()
{
    if (MainMenuSeleccion - 1 <= 4) {
        mainMenu[MainMenuSeleccion].setFillColor(sf::Color::White);
        MainMenuSeleccion++;
        if (MainMenuSeleccion == 4) {
            MainMenuSeleccion = 0;
        }
        mainMenu[MainMenuSeleccion].setFillColor(sf::Color::Blue);
    }
}

int MainMenuExtras::MainMenuPressed()
{
    return MainMenuSeleccion;
}

void MainMenuExtras::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < 4; ++i) {
        target.draw(this->mainMenu[i], states);
    }
}
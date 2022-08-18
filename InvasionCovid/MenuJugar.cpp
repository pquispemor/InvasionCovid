#include "MenuJugar.h"

void MenuJugar::iniciarSprite()
{
    this->textura.loadFromFile("Fondos\\MenuJugar.png");
    this->fondo.setTexture(this->textura);
    if (!font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    int tamsize = 40;
    //*1 jugador
    MenuJugarText[0].setFont(font);
    MenuJugarText[0].setFillColor(sf::Color::White);
    MenuJugarText[0].setString("1  Jugador");
    MenuJugarText[0].setCharacterSize(tamsize);
    MenuJugarText[0].setPosition(330, 270);
    //*2 jugadores
    MenuJugarText[1].setFont(font);
    MenuJugarText[1].setFillColor(sf::Color::White);
    MenuJugarText[1].setString("2  Jugadores");
    MenuJugarText[1].setCharacterSize(tamsize);
    MenuJugarText[1].setPosition(330, 410);
    MenuJugarSeleccion = 0;
    MenuJugarText[MenuJugarSeleccion].setFillColor(sf::Color::Blue);
}

MenuJugar::MenuJugar()
{
    this->iniciarSprite();
}

MenuJugar::~MenuJugar()
{
}

void MenuJugar::MoverArriba()
{
    if (MenuJugarSeleccion - 1 >= 0) {
        MenuJugarText[MenuJugarSeleccion].setFillColor(sf::Color::White);
        MenuJugarSeleccion--;
        if (MenuJugarSeleccion == -1) {
            MenuJugarSeleccion = 1;
        }
        MenuJugarText[MenuJugarSeleccion].setFillColor(sf::Color::Blue);
    }
}

void MenuJugar::MoverAbajo()
{
    if (MenuJugarSeleccion - 1 <= 2) {
        MenuJugarText[MenuJugarSeleccion].setFillColor(sf::Color::White);
        MenuJugarSeleccion++;
        if (MenuJugarSeleccion == 2) {
            MenuJugarSeleccion = 0;
        }
        MenuJugarText[MenuJugarSeleccion].setFillColor(sf::Color::Blue);
    }
}

void MenuJugar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->fondo, states);
    for (int i = 0; i < 2; ++i) {
        target.draw(this->MenuJugarText[i], states);
    }
}

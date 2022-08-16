#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MainMenuExtras : public sf::Drawable
{
private:
    int MainMenuSeleccion;
    sf::Font font;
    sf::Text mainMenu[4];

    void iniciarExtras();
public:
    MainMenuExtras();
    ~MainMenuExtras();
    void MoverArriba();
    void MoverAbajo();
    int MainMenuPressed();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


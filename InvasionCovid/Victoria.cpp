#include "Victoria.h"

void Victoria::iniciarText()
{
    if (!this->fontResultado.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }

    VictoriaText.setFont(this->fontResultado);
    VictoriaText.setCharacterSize(100);
    VictoriaText.setFillColor(sf::Color::White);
    VictoriaText.setString("Victoria");
    VictoriaText.setPosition(250, 200);

    VictoriaAux.setFont(this->fontResultado);
    VictoriaAux.setCharacterSize(50);
    VictoriaAux.setFillColor(sf::Color::White);
    VictoriaAux.setString("Presiona Espacio para Continuar");
    VictoriaAux.setPosition(100, 350);
}

void Victoria::iniciarAudio()
{
    winner.loadFromFile("Audio\\Winner.ogg");
    sound_win.setBuffer(winner);
}

Victoria::Victoria()
{
    this->iniciarText();
    this->iniciarAudio();
}

void Victoria::sonido()
{
    sound_win.play();
}

void Victoria::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->VictoriaText, states);
    target.draw(this->VictoriaAux, states);
}

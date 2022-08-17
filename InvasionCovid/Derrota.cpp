#include "Derrota.h"

void Derrota::iniciarText()
{
    if (!this->fontResultado.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    DerrotaText.setFont(this->fontResultado);
    DerrotaText.setCharacterSize(100);
    DerrotaText.setFillColor(sf::Color::White);
    DerrotaText.setString("Derrota");
    DerrotaText.setPosition(250, 200);

    DerrotaAux.setFont(this->fontResultado);
    DerrotaAux.setCharacterSize(50);
    DerrotaAux.setFillColor(sf::Color::White);
    DerrotaAux.setString("Presiona Escape para Salir");
    DerrotaAux.setPosition(100, 350);
}

void Derrota::iniciarAudio()
{
    loser.loadFromFile("Audio\\Loser.ogg");
    sound_loser.setBuffer(loser);
}

Derrota::Derrota()
{
    this->iniciarText();
}

void Derrota::sonido()
{
    sound_loser.play();
}

void Derrota::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->DerrotaText, states);
    target.draw(this->DerrotaAux, states);
}

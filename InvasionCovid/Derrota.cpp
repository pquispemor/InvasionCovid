#include "Derrota.h"

void Derrota::iniciarGUI()
{
    this->derrotaTexture.loadFromFile("Fondos\\DerrotaResult.png");
    derrota.setTexture(this->derrotaTexture);
    derrota.setPosition(200, 100);
}

void Derrota::iniciarAudio()
{
    loser.loadFromFile("Audio\\Loser2.ogg");
    sound_loser.setBuffer(loser);
}

Derrota::Derrota()
{
    this->iniciarAudio();
    this->iniciarGUI();
}

Derrota* Derrota::get_derrota()
{
    static Derrota d1;
    return &d1;
}

void Derrota::sonido()
{
    sound_loser.play();
}

void Derrota::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->derrota, states);
}

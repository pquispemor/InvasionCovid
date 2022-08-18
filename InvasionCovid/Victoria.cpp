#include "Victoria.h"

void Victoria::iniciarGUI()
{
    this->victoriaTexture.loadFromFile("Fondos\\VictoriaResult.png");
    victoria.setTexture(this->victoriaTexture);
    victoria.setPosition(200, 100);
}

void Victoria::iniciarAudio()
{
    winner.loadFromFile("Audio\\Winner.ogg");
    sound_win.setBuffer(winner);
}

Victoria::Victoria()
{
    this->iniciarGUI();
    this->iniciarAudio();
}

void Victoria::sonido()
{
    sound_win.play();
}

void Victoria::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->victoria, states);
}

#include "SP.h"


void SP::iniciarGUI()
{
    //Cargar Fuente de Letra
    this->puntos = 0;
    if (!this->font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    //Puntuacion
    puntuacionText.setFont(this->font);
    puntuacionText.setCharacterSize(30);
    puntuacionText.setFillColor(sf::Color::White);
    puntuacionText.setString("0");
    puntuacionText.setPosition(200, 8);

    //Vida
    float d = 650;
    for (int i = 0; i < 3; i++) {
        this->vidas.push_back(new Vida(d, 10));
        d += 50;
    }
}

void SP::iniciarJugador1()
{
    this->jugador1 = new Jugador1();
    std::cout << *this->jugador1;
}


void SP::iniciarTextureBalas()
{
    this->textures["BALAS"] = new sf::Texture();
    this->textures["BALAS"]->loadFromFile("Sprites\\DisparoPlayer1.png");
}


void SP::iniciarAudiosFijos()
{
    Atras.loadFromFile("Audio\\Salir.ogg");
    sound_Atras.setBuffer(Atras);
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    enemigoDead.loadFromFile("Audio\\EnemigoDead.ogg");
    sound_enemigoDead.setBuffer(enemigoDead);
    impacto.loadFromFile("Audio\\ImpactoNave.ogg");
    sound_impacto.setBuffer(impacto);
}


void SP::updateEntrada()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->jugador1->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->jugador1->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->jugador1->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->jugador1->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->jugador1->puedesAtacar()) {
        this->balas.push_back(new Bala(this->textures["BALAS"],
            this->jugador1->getPos().x + this->jugador1->getLimites().width / 2.f,
            this->jugador1->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }
}


void SP::updatePuntuacion()
{
    std::stringstream ss;

    ss << this->puntos;

    this->puntuacionText.setString(ss.str());
    

    std::stringstream sn;
    sn << this->nivel;
    this->nivelText.setString(sn.str());

    if (puntos >= 500) {
        if (cambio1 == 0) {
            this->texture.loadFromFile("Fondos\\Fase2.png");
            fondo.setTexture(this->texture);
            cambio1 = 1;
            nivel++;
        }
    }
    if (puntos >= 1000) {
        if (cambio2 == 0) {
            this->texture.loadFromFile("Fondos\\Fase3.png");
            fondo.setTexture(this->texture);
            cambio2 = 1;
            nivel++;
        }
    }

    if (puntos >= 1500) {
        if (cambio3 == 0) {
            this->texture.loadFromFile("Fondos\\Fase4.png");
            fondo.setTexture(this->texture);
            cambio3 = 1;
            nivel++;
        }
    }

    if (puntos >= 2000) {
        if (cambio4 == 0) {
            this->texture.loadFromFile("Fondos\\Fase5.png");
            fondo.setTexture(this->texture);
            cambio4 = 1;
            nivel++;
        }
    }

    if (puntos >= 2500) {
        victoria = true;
    }

}

void SP::updateBalas()
{
    unsigned counter = 0;
    for (auto* bala : this->balas) {
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if (bala->getLimites().top + bala->getLimites().height < 100.f) {
            //*Eliminar Bala
            delete this->balas.at(counter);
            this->balas.erase(this->balas.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

bool SP::resultado()
{
    return victoria;
}


#pragma once

#ifndef MULTIPLAYERJUEGO_H
#define MULTIPLAYERJUEGO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <vector>
#include "JugadorMain.h"
#include "Jugador1.h"
#include "Jugador2.h"
#include "Bala.h"
#include "Bala2.h"
#include "Enemigo.h"
#include "Vida.h"
#include <iostream>
#include <string>
#include <sstream>
#include "MPEtapa1.h"

class MultiplayerJuego
{
protected:

    //*Ventana
    sf::RenderWindow* window;

    //*Audio
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer EnemigoDead;
    sf::Sound sound_EnemigoDead;
    sf::SoundBuffer Winner;
    sf::Sound sound_Winner;
    sf::SoundBuffer Loser;
    sf::Sound sound_Loser;
    sf::SoundBuffer DañoJugador;
    sf::Sound sound_DañoJugador;

    //BALAS
    std::map<std::string, sf::Texture*> texturesBala1;
    std::map<std::string, sf::Texture*> texturesBala2;
    std::vector<Bala*> balasJugador1;
    std::vector<Bala2*> balasJugador2;

    //PUNTOS
    sf::Font font;
    sf::Text Fase1Text[2];
    unsigned puntos;

    //RESULTADOS VICTORIA O DERRORA
    sf::Font fontResultado;
    sf::Text DerrotaText;
    sf::Text VictoriaText;

    //VIDAS
    int cantVidas = 3;
    std::vector<Vida*> vidas;
    bool derrota = false;
    bool victoria = false;

    //JUGADORES
    JugadorMain* jugador1;
    JugadorMain* jugador2;

    //Etapas
    //Etapa 1
    MPEtapa1 mpetapa1;


    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    std::vector<Enemigo*> enemigos;

    void iniciarWindow();
    
    void iniciarTextureBalas();

    void iniciarResultado();
    void iniciarPuntuacion();
    void iniciarJugadores();
    void iniciarVida();
    void iniciarEnemigo();
    void iniciarAudio();

public:
    MultiplayerJuego(/* args */);
    ~MultiplayerJuego();
    void run();

    void updatePollEvents();
    void updateEntrada();
    void updateCollision();
    void updatePuntuacion();
    void updateBalasJugador1();
    void updateBalasJugador2();
    void updateEnemigo();
    void updateCombate();
    void update();
    void render();
};

#endif
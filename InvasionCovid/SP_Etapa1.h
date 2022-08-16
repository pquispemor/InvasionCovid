#pragma once
#ifndef SP_ETAPA1_H
#define SP_ETAPA1_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <chrono>
#include <map>
#include <vector>
#include "Jugador1.h"
#include "Bala.h"
#include "MinionEtapa1.h"
#include "Vida.h"
#include <iostream>
#include <string>
#include <sstream>

class SP_Etapa1
{
private:

    //*Ventana
    sf::RenderWindow* window;
    sf::Sprite fondo;
    sf::Texture texture;

    sf::SoundBuffer fase1;
    sf::Sound sound_fase1;
    sf::SoundBuffer Atras;
    sf::Sound sound_Atras;
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer m1Dead;
    sf::Sound sound_m1Dead;
    sf::SoundBuffer winner;
    sf::Sound sound_win;
    sf::SoundBuffer loser;
    sf::Sound sound_loser;
    sf::SoundBuffer impacto;
    sf::Sound sound_impacto;

    //*Recursos
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bala*> balas;

    //*Puntos System
    sf::Font font;
    sf::Text Fase1Text[2];

    //*Resultado Text
    sf::Font fontResultado;
    sf::Text DerrotaText;
    sf::Text VictoriaText;

    //*Vidas
    int cantVidas = 3;
    std::vector<Vida*> vidas;
    bool derrota = false;
    bool victoria = false;

    //* Puntuacion

    unsigned puntos;
    //*Jugador1
    Jugador1* jugador1;


    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    std::vector<MinionEtapa1*> minions1;
    int unaVez = 1;

    void iniciarWindow();
    void iniciarTexture();

    void iniciarVida();
    void iniciarPuntuacion();
    void iniciarJugador1();
    void iniciarMinion1();
    void iniciarResultado();

public:
    SP_Etapa1(/* args */);
    ~SP_Etapa1();
    void run();

    void updatePollEvents();
    void updateEntrada();
    void updateCollision();
    void updatePuntuacion();
    void updateBalas();
    void updateMinion1();
    void updateCombate();
    void update();
    void render();
    void renderPuntuacion();
};

#endif
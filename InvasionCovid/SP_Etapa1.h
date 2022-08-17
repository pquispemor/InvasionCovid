#pragma once
#ifndef SP_ETAPA1_H
#define SP_ETAPA1_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <chrono>

//Clases
#include "MinionEtapa1.h"
#include "SP.h"

class SP_Etapa1 : public SP
{
private:

    //*Ventana
    sf::RenderWindow* window;
    int anchura = 800;
    int altura = 600;

    sf::SoundBuffer fase;
    sf::Sound sound_fase;


    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    std::vector<MinionEtapa1*> minions1;
    int unaVez = 1;
    int tipo1 = 0;

    void iniciarWindow();
    void iniciarEnemigo();
    void iniciarTextureFondo();
    void iniciarAudioFase();
    void iniciarGUINivel();

public:
    SP_Etapa1(/* args */);
    ~SP_Etapa1();
    void updatePollEvents();
    void updateEnemigo();
    void updateCombate();
    void update();
    void render();
    void run();
    void windowClose();
};

#endif
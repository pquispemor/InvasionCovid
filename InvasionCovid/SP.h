#pragma once
#ifndef SP_H
#define SP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

//Clases
#include "Jugador1.h"
#include "Bala.h"
#include "Vida.h"
#include "MinionEtapa1.h"

//Textos Victoria y Derrota
#include "Victoria.h"
#include "Derrota.h"


class SP
{
protected:
    //*Ventana
    sf::RenderWindow* window;
    int anchura = 800;
    int altura = 600;
    int fps = 60;

    sf::Sprite fondo;
    sf::Texture texture;

    sf::Texture textureEnemigo;
    int cambio1 = 0;
    int cambio2 = 0;
    int cambio3 = 0;
    int cambio4 = 0;

    sf::SoundBuffer Atras;
    sf::Sound sound_Atras;
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer enemigoDead;
    sf::Sound sound_enemigoDead;
    sf::SoundBuffer impacto;
    sf::Sound sound_impacto;

    //*Recursos
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bala*> balas;

    // ---- GUI ---
    //*Puntuacion
    sf::Font font;
    sf::Text puntuacionText;
    unsigned puntos;
    unsigned nivel = 1;

    //Nivel
    sf::Text nivelText;

    //Vidas
    int cantVidas = 3;
    std::vector<Vida*> vidas;

    //*Resultado Text
    sf::Font fontResultado;
    Derrota resultD;
    Victoria resultV;
    bool derrota = false;
    bool victoria = false;

    //*Jugador1
    Jugador1* jugador1;

    
    void iniciarTextureBalas();
    void iniciarGUI();
    void iniciarJugador1();
    void iniciarAudiosFijos();
    virtual void iniciarEnemigo() {};
    virtual void iniciarTextureFondo() {};
    virtual void iniciarAudioFase() {};
    virtual void iniciarGUINivel() {};
public:

    SP(/* args */) {};
    ~SP() {};
    void updateEntrada();
    void updatePuntuacion();
    void updateBalas();
    bool resultado();
    virtual void updateEnemigo() {};
    virtual void updateCombate() {};
    virtual void update() {};
    virtual void render() {};
    virtual void run() {};
};

#endif
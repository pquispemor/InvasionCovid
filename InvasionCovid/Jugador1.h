#pragma once
#ifndef JUGADOR1_H
#define JUGADOR1_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "JugadorMain.h"

class Jugador1 : public JugadorMain
{
private:
    int tipo = 1;
public:
    Jugador1();
    ~Jugador1();
    void IniciarSpriteYPos();
    friend std::ostream& operator<<(std::ostream& out, const Jugador1& p);


};

#endif


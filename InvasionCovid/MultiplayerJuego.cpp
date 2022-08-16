#include "MultiplayerJuego.h"

void MultiplayerJuego::iniciarWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Fase1");
    this->window->setFramerateLimit(60);
}

void MultiplayerJuego::iniciarTextureBalas() {
    //Bala Jugador 1
    this->texturesBala1["BALAS1"] = new sf::Texture();
    this->texturesBala1["BALAS1"]->loadFromFile("Sprites\\DisparoPlayer1.png");
    
    //Bala Jugador 2
    this->texturesBala1["BALAS2"] = new sf::Texture();
    this->texturesBala1["BALAS2"]->loadFromFile("Sprites\\DisparoPlayer2.png");
    
}


void MultiplayerJuego::iniciarPuntuacion() {
    //Cargar Fuente de Letra
    this->puntos = 0;
    if (!this->font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    //Nivel
    Fase1Text[0].setFont(this->font);
    Fase1Text[0].setCharacterSize(30);
    Fase1Text[0].setFillColor(sf::Color::White);
    Fase1Text[0].setString("1");
    Fase1Text[0].setPosition(440, 8);

    //Puntuacion
    Fase1Text[1].setFont(this->font);
    Fase1Text[1].setCharacterSize(30);
    Fase1Text[1].setFillColor(sf::Color::White);
    Fase1Text[1].setString("0");
    Fase1Text[1].setPosition(200, 8);


}


void MultiplayerJuego::iniciarResultado() {
    if (!this->fontResultado.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    DerrotaText.setFont(this->fontResultado);
    DerrotaText.setCharacterSize(100);
    DerrotaText.setFillColor(sf::Color::White);
    DerrotaText.setString("Derrota");
    DerrotaText.setPosition(this->window->getSize().x / 2 - 150, this->window->getSize().y / 2 - 100);

    VictoriaText.setFont(this->fontResultado);
    VictoriaText.setCharacterSize(100);
    VictoriaText.setFillColor(sf::Color::White);
    VictoriaText.setString("Victoria");
    VictoriaText.setPosition(this->window->getSize().x / 2 - 150, this->window->getSize().y / 2 - 100);
}


void MultiplayerJuego::iniciarJugadores() {
    this->jugador1 = new Jugador1();
    this->jugador2 = new Jugador2();
}

void MultiplayerJuego::iniciarVida() {
    int d = 650;
    for (int i = 0; i < 3; i++) {
        this->vidas.push_back(new Vida(d, 10));
        d += 50;
    }
}

void MultiplayerJuego::iniciarEnemigo()
{
    this->tiempoSpawnMax = 20.f;
    this->tiempoSpawn = this->tiempoSpawnMax;
}

void MultiplayerJuego::iniciarAudio()
{
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    EnemigoDead.loadFromFile("Audio\\minionDead.ogg");
    sound_EnemigoDead.setBuffer(EnemigoDead);
    Winner.loadFromFile("Audio\\Winner.ogg");
    sound_Winner.setBuffer(Winner);
    Loser.loadFromFile("Audio\\Loser.ogg");
    sound_Loser.setBuffer(Loser);
    DañoJugador.loadFromFile("Audio\\ImpactoNave.ogg");
    sound_DañoJugador.setBuffer(DañoJugador);

}


MultiplayerJuego::MultiplayerJuego()
{
    this->iniciarWindow();
    this->iniciarTextureBalas();
    this->iniciarPuntuacion();
    this->iniciarResultado();
    this->iniciarJugadores();
    this->iniciarVida();
    this->iniciarEnemigo();
    this->iniciarAudio();
}

MultiplayerJuego::~MultiplayerJuego()
{
    delete this->window;
    delete this->jugador1;
    delete this->jugador2;

    //*Eliminar texturas Balas
    for (auto& i : this->texturesBala1) {
        delete i.second;
    }
   
    for (auto& i : this->texturesBala2) {
        delete i.second;
    }
   

    //*Eliminar Balas
    for (auto* i : this->balasJugador1) {
        delete i;
    }
     
    for (auto* i : this->balasJugador2) {
        delete i;
    }
   

    //*Eliminar Minions1
    for (auto* i : this->enemigos) {
        delete i;
    }
}

void MultiplayerJuego::run() {
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void MultiplayerJuego::updatePollEvents() {
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed) {
            this->window->close();
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
            this->window->close();
        }
    }
}

void MultiplayerJuego::updateEntrada() {
    //Jugador1 update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->jugador1->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->jugador1->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->jugador1->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->jugador1->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->jugador1->puedesAtacar()) {
        this->balasJugador1.push_back(new Bala(this->texturesBala1["BALAS1"],
            this->jugador1->getPos().x + this->jugador1->getLimites().width / 2.f,
            this->jugador1->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }

    //Jugador2 update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->jugador2->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->jugador2->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->jugador2->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->jugador2->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && this->jugador2->puedesAtacar()) {
        this->balasJugador2.push_back(new Bala2(this->texturesBala2["BALAS2"],
            this->jugador2->getPos().x + this->jugador2->getLimites().width / 2.f,
            this->jugador2->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }

}

void MultiplayerJuego::updatePuntuacion() {
    std::stringstream ss;

    ss << this->puntos;

    this->Fase1Text[1].setString(ss.str());

    if (puntos >= 500) {
        victoria = true;
    }

    //*Vidas

}


void MultiplayerJuego::updateCollision() {
    //*Colision Pantalla-Jugador1
        //*Colision Izquierda
        if (this->jugador1->getLimites().left < 0.f) {
            this->jugador1->setPosition(0.f, this->jugador1->getLimites().top);
        }
        //*Colision Derecha
        else if (this->jugador1->getLimites().left + this->jugador1->getLimites().width >= this->window->getSize().x) {
            this->jugador1->setPosition(this->window->getSize().x - this->jugador1->getLimites().width, this->jugador1->getLimites().top);
        }
        //*Colision Arriba
        if (this->jugador1->getLimites().top < 0.f) {
            this->jugador1->setPosition(this->jugador1->getLimites().left, 0.f);
        }

        //*Colision Abajo
        else if (this->jugador1->getLimites().top + this->jugador1->getLimites().height >= this->window->getSize().y) {
            this->jugador1->setPosition(this->jugador1->getLimites().left, this->window->getSize().y - this->jugador1->getLimites().height);
        }
    //Colision Pantalla-Jugador2
        if (this->jugador2->getLimites().left < 0.f) {
            this->jugador2->setPosition(0.f, this->jugador2->getLimites().top);
        }
        //*Colision Derecha
        else if (this->jugador2->getLimites().left + this->jugador2->getLimites().width >= this->window->getSize().x) {
            this->jugador2->setPosition(this->window->getSize().x - this->jugador2->getLimites().width, this->jugador2->getLimites().top);
        }
        //*Colision Arriba
        if (this->jugador2->getLimites().top < 0.f) {
            this->jugador2->setPosition(this->jugador2->getLimites().left, 0.f);
        }

        //*Colision Abajo
        else if (this->jugador2->getLimites().top + this->jugador2->getLimites().height >= this->window->getSize().y) {
            this->jugador2->setPosition(this->jugador2->getLimites().left, this->window->getSize().y - this->jugador2->getLimites().height);
        }
}

void MultiplayerJuego::updateBalasJugador1() {

    unsigned counter = 0;
    for (auto* bala : this->balasJugador1) {
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if (bala->getLimites().top + bala->getLimites().height < 100.f) {
            //*Eliminar Bala
            delete this->balasJugador1.at(counter);
            this->balasJugador1.erase(this->balasJugador1.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

void MultiplayerJuego::updateBalasJugador2() {

    unsigned counter = 0;
    for (auto* bala : this->balasJugador2) {
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if (bala->getLimites().top + bala->getLimites().height < 100.f) {
            //*Eliminar Bala
            delete this->balasJugador2.at(counter);
            this->balasJugador2.erase(this->balasJugador2.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

void MultiplayerJuego::updateEnemigo() {
    this->tiempoSpawn += 0.5f;
    if (this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->enemigos.push_back(new Enemigo(rand() % this->window->getSize().x - 20.f, 50.f));
        this->tiempoSpawn = 0.f;
    }

    //*Update
    unsigned counter = 0;
    for (auto* enemigo : this->enemigos) {
        enemigo->update();

        //*Enemigos Colision con Pantalla
        if (enemigo->getLimites().top > this->window->getSize().y) {
            //*Eliminar Enemigo
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;

        }

        //*Colision enemigo - Jugador
        else if (enemigo->getLimites().intersects(this->jugador1->getLimites())) {
            delete this->vidas.at(0);
            this->vidas.erase(this->vidas.begin() + 0);
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;
            sound_DañoJugador.play();
        }

        ++counter;
    }
    if (vidas.size() == 0) {
        sound_Loser.play();
        derrota = true;
    }

}

void MultiplayerJuego::updateCombate() {
    for (int i = 0; i < this->enemigos.size(); i++) {

        bool enemigo_delete = false;
        for (size_t k{ 0 }; k < this->balasJugador1.size() && enemigo_delete == false; k++) {
            if (this->enemigos[i]->getLimites().intersects(this->balasJugador1[k]->getLimites())) {

                this->puntos += this->enemigos[i]->getPuntos();

                delete this->enemigos[i];
                this->enemigos.erase(this->enemigos.begin() + i);

                delete this->balasJugador1[k];
                this->balasJugador1.erase(this->balasJugador1.begin() + k);


                enemigo_delete = true;
                sound_EnemigoDead.play();
            }
        }

    }
}

void MultiplayerJuego::update() {
    this->updatePollEvents();

    this->updateEntrada();

    this->jugador1->update();

    this->jugador2->update();

    this->updateCollision();

    this->updateBalasJugador1();

    this->updateBalasJugador2();

    if (derrota == false and victoria == false) {
        this->updateEnemigo();
    }
    this->updateCombate();

    this->updatePuntuacion();
}


void MultiplayerJuego::render() {
    this->window->clear();
    this->window->draw(this->mpetapa1);
    this->window->draw(*this->jugador1);
    this->window->draw(*this->jugador2);

    //Dibujo Balas Jugadores
    for (auto* bala1 : this->balasJugador1) {
        this->window->draw(*bala1);
    }

    for (auto* bala2 : this->balasJugador2) {
        this->window->draw(*bala2);
    }

    //Dibujo Vidas
    for (auto* vida : this->vidas) {
        this->window->draw(*vida);
    }

    //Dibujo Enemigos
    for (auto* enemigo : this->enemigos) {
        this->window->draw(*enemigo);
    }

    //Dibujo Victoria
    if (victoria == true) {
        this->window->draw(VictoriaText);
    }
    if (derrota == true) {
        this->window->draw(DerrotaText);
    }

    //Dibujo Puntuacion
    for (int i = 0; i < 2; ++i) {
        this->window->draw(Fase1Text[i]);
    }

    this->window->display();

}
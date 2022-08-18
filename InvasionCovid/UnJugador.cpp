#include "UnJugador.h"

auto eng = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(eng);
std::uniform_int_distribution<> rand_digits(0, 750);

void UnJugador::iniciarWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(anchura, altura), "Un Jugador");
	this->window->setFramerateLimit(fps);
}

void UnJugador::iniciarEnemigo()
{
	this->tiempoSpawnMax = 20.f;
	this->tiempoSpawn = this->tiempoSpawnMax;
}

void UnJugador::iniciarJugador1()
{
	this->jugador1 = new Jugador1();
	std::cout << *this->jugador1;
}

void UnJugador::iniciarTextureFondo()
{
	this->texture.loadFromFile("Fondos\\Fase1.png");
	fondo.setTexture(this->texture);
}

void UnJugador::iniciarTextureBalas()
{
	this->textures["BALAS"] = new sf::Texture();
	this->textures["BALAS"]->loadFromFile("Sprites\\DisparoPlayer1.png");
}

void UnJugador::iniciarGUI()
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
    float distanciaVida = 650;
    for (int i = 0; i < 3; i++) {
        this->vidas.push_back(new Vida(distanciaVida, 10));
        distanciaVida += 50;
    }
    //Nivel
    //Cargar Fuente de Letra
    if (!this->font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    //*Nivel
    nivelText.setFont(this->font);
    nivelText.setCharacterSize(30);
    nivelText.setFillColor(sf::Color::White);
    nivelText.setString("1");
    nivelText.setPosition(440, 8);
}

void UnJugador::iniciarAudioFase()
{
    fase.loadFromFile("Audio\\Musica1.ogg");
    sound_fase.setBuffer(fase);
    sound_fase.setVolume(50);
    sound_fase.play();
}

void UnJugador::iniciarAudiosFijos()
{
    Atras.loadFromFile("Audio\\Salir.ogg");
    sound_Atras.setBuffer(Atras);
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    sound_Disparo.setVolume(50);
    enemigoDead.loadFromFile("Audio\\EnemigoDead2.ogg");
    sound_enemigoDead.setBuffer(enemigoDead);
    impacto.loadFromFile("Audio\\ImpactoNave.ogg");
    sound_impacto.setBuffer(impacto);
}

UnJugador::UnJugador()
{
    this->iniciarWindow();
    this->iniciarTextureBalas();
    this->iniciarGUI();
    this->iniciarJugador1();
    this->iniciarAudiosFijos();
    this->iniciarEnemigo();
    this->iniciarTextureFondo();
    this->iniciarAudioFase();
}

UnJugador::~UnJugador()
{
    delete this->window;
    delete this->jugador1;

    //*Eliminar texturas
    for (auto& i : this->textures) {
        delete i.second;
    }

    //*Eliminar Balas
    for (auto* i : this->balas) {
        delete i;
    }

    //*Eliminar Minions1
    for (auto* i : this->enemigos) {
        delete i;
    }
}

void UnJugador::updateEntrada()
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

void UnJugador::updatePuntuacion_Nivel()
{
    std::stringstream ss;

    ss << this->puntos;

    this->puntuacionText.setString(ss.str());


    std::stringstream sn;
    sn << this->nivel;
    this->nivelText.setString(sn.str());
}

void UnJugador::updateEscenario()
{
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
        if (ResultadoVUnaVez == 0) {
            resultV.sonido();
            ResultadoVUnaVez = 1;
        }
    }
}

void UnJugador::updateBalas()
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

void UnJugador::updatePollEvents()
{
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed) {
            sound_Atras.play();
            this->window->close();
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
            sound_Atras.play();
            this->window->close();
        }
    }
}


void UnJugador::updateEnemigo()
{
    this->tiempoSpawn += 0.5f;
    if (this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->enemigos.push_back(new Enemigo(rand_digits(gen), 50.f));
        this->tiempoSpawn = 0.f;
    }
    if (unaVez == 1) {
        std::cout << *this->enemigos[0];
        unaVez++;
    }

    //*Update
    unsigned counter = 0;
    for (auto* minion1 : this->enemigos) {
        minion1->update();

        //Actualizacion de Enemigo por Niveles

        if (puntos > 500) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion2.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(8.f);
        }
        if (puntos > 1000) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion3.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(10.f);
        }
        if (puntos > 1500) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion4.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(12.f);
        }
        if (puntos > 2000) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion5.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(14.f);
        }

        //*Enemigos Colision con Pantalla
        if (minion1->getLimites().top > this->window->getSize().y) {
            //*Eliminar Enemigo
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;

        }

        //*Colision enemigo - Jugador
        else if (minion1->getLimites().intersects(this->jugador1->getLimites())) {
            delete this->vidas.at(0);
            this->vidas.erase(this->vidas.begin() + 0);
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;
            sound_impacto.play();
        }

        ++counter;
    }
    if (vidas.size() == 0) {
        derrota = true;
    }
}

void UnJugador::updateCombate()
{
    for (int i = 0; i < this->enemigos.size(); i++) {

        bool minion1_delete = false;
        for (size_t k{ 0 }; k < this->balas.size() && minion1_delete == false; k++) {
            if (this->enemigos[i]->getLimites().intersects(this->balas[k]->getLimites())) {

                this->puntos += this->enemigos[i]->getPuntos();
                delete this->enemigos[i];
                this->enemigos.erase(this->enemigos.begin() + i);

                delete this->balas[k];
                this->balas.erase(this->balas.begin() + k);

                minion1_delete = true;
                sound_enemigoDead.play();
            }
        }

    }
}

void UnJugador::update()
{
    this->updatePollEvents();

    if (derrota == false and victoria == false) {
        this->updateEntrada();
        this->jugador1->update();
        this->updateBalas();
        this->updateEnemigo();
    }

    this->updateEscenario();

    this->updateCombate();

    this->updatePuntuacion_Nivel();
}

void UnJugador::render()
{
    this->window->clear();
    this->window->draw(fondo);
    this->window->draw(*this->jugador1);

    for (auto* bala : this->balas) {
        this->window->draw(*bala);
    }

    for (auto* vida : this->vidas) {
        this->window->draw(*vida);
    }

    for (auto* minion1 : this->enemigos) {
        this->window->draw(*minion1);
    }
    if (victoria == true) {
        this->window->draw(resultV);
        sound_fase.stop();
    }
    if (derrota == true) {
        this->window->draw(resultD);
        sound_fase.stop();
        if (ResultadoDUnaVez == 0) {
            resultD.sonido();
            ResultadoDUnaVez = 1;
        }
    }
    this->window->draw(puntuacionText);
    this->window->draw(nivelText);

    this->window->display();
}

void UnJugador::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}


#include "SP_Etapa1.h"

auto eng = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(eng);
std::uniform_int_distribution<> rand_digits(0, 800);

void SP_Etapa1::iniciarWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(anchura, altura), "Fase1");
    this->window->setFramerateLimit(fps);
}

void SP_Etapa1::iniciarTextureFondo() {
    this->texture.loadFromFile("Fondos\\Fase1.png");
    fondo.setTexture(this->texture);
}

void SP_Etapa1::iniciarAudioFase()
{
    fase.loadFromFile("Audio\\Fase1-Batalla2.ogg");
    sound_fase.setBuffer(fase);
    sound_fase.setVolume(50);
    sound_fase.play();
}

void SP_Etapa1::iniciarGUINivel()
{
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

void SP_Etapa1::iniciarEnemigo() {
    this->tiempoSpawnMax = 20.f;
    this->tiempoSpawn = this->tiempoSpawnMax;
}

SP_Etapa1::SP_Etapa1()
{
    this->iniciarWindow();
    this->iniciarTextureBalas();
    this->iniciarGUI();
    this->iniciarJugador1();
    this->iniciarAudiosFijos();
    this->iniciarEnemigo();
    this->iniciarTextureFondo();
    this->iniciarAudioFase();
    this->iniciarGUINivel();
    sound_fase.play();
    sound_fase.setVolume(50);
}

SP_Etapa1::~SP_Etapa1()
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
    for (auto* i : this->minions1) {
        delete i;
    }
}

void SP_Etapa1::updatePollEvents()
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

void SP_Etapa1::updateEnemigo() {
    this->tiempoSpawn += 0.5f;
    if (this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->minions1.push_back(new MinionEtapa1(rand_digits(gen), 50.f));
        this->tiempoSpawn = 0.f;
    }
    if (unaVez == 1) {
        std::cout << *this->minions1[0];
        unaVez++;
    }

    //*Update
    unsigned counter = 0;
    for (auto* minion1 : this->minions1) {
        minion1->update();
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
            delete this->minions1.at(counter);
            this->minions1.erase(this->minions1.begin() + counter);
            --counter;

        }

        //*Colision enemigo - Jugador
        else if (minion1->getLimites().intersects(this->jugador1->getLimites())) {
            delete this->vidas.at(0);
            this->vidas.erase(this->vidas.begin() + 0);
            delete this->minions1.at(counter);
            this->minions1.erase(this->minions1.begin() + counter);
            --counter;
            sound_impacto.play();
        }

        ++counter;
    }
    if (vidas.size() == 0) {
        derrota = true;
    }

}

void SP_Etapa1::updateCombate() {
    for (int i = 0; i < this->minions1.size(); i++) {

        bool minion1_delete = false;
        for (size_t k{ 0 }; k < this->balas.size() && minion1_delete == false; k++) {
            if (this->minions1[i]->getLimites().intersects(this->balas[k]->getLimites())) {

                this->puntos += this->minions1[i]->getPuntos();

                delete this->minions1[i];
                this->minions1.erase(this->minions1.begin() + i);

                delete this->balas[k];
                this->balas.erase(this->balas.begin() + k);

                minion1_delete = true;
                sound_enemigoDead.play();
            }
        }

    }
}

void SP_Etapa1::update() {
    this->updatePollEvents();

    if (derrota == false and victoria == false) {
        this->updateEntrada();
        this->jugador1->update();
        this->updateBalas();
        this->updateEnemigo();
    }
    this->updateCombate();

    this->updatePuntuacion();
}


void SP_Etapa1::render() {
    this->window->clear();
    this->window->draw(fondo);
    this->window->draw(*this->jugador1);

    for (auto* bala : this->balas) {
        this->window->draw(*bala);
    }

    for (auto* vida : this->vidas) {
        this->window->draw(*vida);
    }

    for (auto* minion1 : this->minions1) {
        this->window->draw(*minion1);
    }
    if (victoria == true) {
        this->window->draw(resultV);
        sound_fase.stop();
    }
    if (derrota == true) {
        this->window->draw(resultD);
        sound_fase.stop();
    }
    this->window->draw(puntuacionText);
    this->window->draw(nivelText);

    this->window->display();

}

void SP_Etapa1::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void SP_Etapa1::windowClose()
{
    this->window->close();
}

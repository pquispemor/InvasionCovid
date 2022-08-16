#pragma once
#ifndef MPETAPA1_H
#define MPETAPA1_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MPEtapa1 : public sf::Drawable
{
private:
	sf::Sprite fondo;
	sf::Texture texture;
	void iniciarInterfaz();
public:
	MPEtapa1();
	~MPEtapa1();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif
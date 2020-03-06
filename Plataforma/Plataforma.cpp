#include <SFML/Graphics.hpp>
#include "Plataforma.h"


Plataforma::~Plataforma(){}
Plataforma:: Plataforma(sf::Texture* textura, sf::Vector2f size, sf::Vector2f posicion){
             
            body.setSize(size);
            body.setOrigin(size/ 2.0f);
            body.setTexture(textura);//aqui hay que añadir el sprite
            body.setPosition(posicion);//Quitar esto mas adelante
}

void Plataforma:: Draw(sf::RenderWindow& window){ window.draw(body);}

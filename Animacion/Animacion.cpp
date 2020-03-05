#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Animacion::~Animacion(){}
Animacion::Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite){

    this->cantidadImagenes=cantidadImagenes;
    this->SwitchTimeSprite=SwitchTimeSprite;

    spriteActual.y= 0;
    spriteActual.x = 0;
    
    temporizador = 0;


    textureRect.height = textura->getSize().y/ float(cantidadImagenes.y);
    textureRect.width = textura->getSize().x/ float(cantidadImagenes.x);

}

void Animacion::Update(float deltaTime){


    textureRect.left = spriteActual.x * textureRect.width;
    textureRect.top = spriteActual.y * textureRect.height;

}

void Animacion::setSprite(sf::Vector2u sprites){
    spriteActual.x = sprites.x;
    spriteActual.y = sprites.y;
}
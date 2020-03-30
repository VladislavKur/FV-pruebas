#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemigo.h"
#include "../Collider/Collider.h"
#include "../Plataforma/Plataforma.h"

#ifndef REPTANTE_H
#define REPTANTE_H


class Reptante : public Enemigo{
    private:
        sf::RectangleShape esqIzq;
        sf::RectangleShape esqDcha;
       
        int direccion;
    public:
        Reptante(sf::Texture& tex, float x, float y);
        //void update(sf::RectangleShape& player, float delta);
        void update(float deltaTime, Plataforma plataforma, Plataforma suelo);
        void render(sf::RenderWindow& entrada, float porcentaje);   
        Collider getCollider(){return Collider(cuerpo);}

        void moveRight(float deltaTime);
        void moveLeft(float deltaTime);
        
        sf::FloatRect coliAbajo;
        sf::FloatRect coliArriba;
        sf::FloatRect coliIzquierda;
        sf::FloatRect coliDerecha;
};

#endif

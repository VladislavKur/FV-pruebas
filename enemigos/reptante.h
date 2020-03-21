#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemigo.h"

#ifndef REPTANTE_H
#define REPTANTE_H
/*
class Reptante{

    public:
        Reptante(sf::Texture& tex);
        Reptante(sf::Texture& tex,int x, int y);
        void update(sf::RectangleShape& entrada);
        void render(sf::RenderWindow& entrada, float porcentaje);
    private:
        void actualizarPosicion(float entradaX, float entradaY);
        float posX;
        float posY;
        float posXanterior;
        float posYanterior;
        float diffX;
        float diffY;
        float velocidad = 6;
        int modo;
        //modo: 0 suelo, modo: 1 paredI, modo: 2 techo, modo: 3 paredD
        sf::Sprite cuerpo;
        sf::RectangleShape esqSuperior;
        sf::RectangleShape esqInf;
};
*/

class Reptante : public Enemigo{
    private:
        sf::RectangleShape esqIzq;
        sf::RectangleShape esqDcha;
        int direccion;
    protected:
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};

#endif

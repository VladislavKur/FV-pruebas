#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MURCIELAGO_H
#define MURCIELAGO_H

class Murcielago{

    public:
        Murcielago(sf::Texture& tex);
        Murcielago(sf::Texture& tex,int x, int y);
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
        float direccion = 0;
        float velocidad = 4;
        int modo;
        //0: colgado 1:cayendo(diagonal-parabola) 2:recto
        sf::Sprite cuerpo;
        static const int altura = 0;
        static const int distanciaAcercamiento = 1000;
        //static const int distanciaDisparo = 100;
        

};

#endif

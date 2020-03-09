#pragma once
#include <SFL/Graphics.hpp>
#include <iostream>

#ifndef CENTINELA_H
#define CENTINELA_H

class Centinela{

    public:
        Centinela(sf::Texture& tex);
        Centinela(sf::Texture& tex,int x, int y);
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
        //modo: 0 quieto, modo: 1 caminar, modo: 2 matar
        sf::Sprite cuerpo;
        static const int distanciaAcercamiento = 600;
        static const int distanciaDisparo = 100;

};

#endif

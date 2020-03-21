#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemigo.h"

#ifndef CENTINELA_H
#define CENTINELA_H

class Centinela : public Enemigo{
    private:
        int distanciaAtaque;
        int distanciaDisparo;
        void disparar(); //devuelve bala o nada ??????

    public:
        Centinela(sf::Texture& tex, float x, float y):Enemigo(tex, x, y){}
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};

#endif

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "enemigo.h"

#ifndef MURCIELAGO_H
#define MURCIELAGO_H


class Murcielago : public Enemigo{
    private:
        int distanciaAtaque;
        int altura;
        int direccion = 0;
        bool haPegado;
    public:
        Murcielago(sf::Texture& tex, float x, float y):Enemigo(tex, x, y){}
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);  
         
};

#endif

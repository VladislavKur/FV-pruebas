#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemigo.h"

#ifndef REPTANTE_H
#define REPTANTE_H


class Reptante : public Enemigo{
    private:
        sf::RectangleShape esqIzq;
        sf::RectangleShape esqDcha;
        int direccion;
    public:
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};
#endif

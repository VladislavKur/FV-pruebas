#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player.h>


#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo{
    public:
        Enemigo(sf::Texture tex, float x, float y);
        ~Enemigo();
        virtual void update(sf::RectangleShape& player, float delta); ///player
        virtual void render(sf::RenderWindow & entrada, float porcentaje);

    protected:
        float posX, posY;
        float posXanterior, posYanterior;
        float diffX, diffY;
        float velocidad;
        int modo;
        sf::RectangleShape cuerpo;
        sf::Clock relojAnim;
        void actualizarPosicion(float x, float y);
};
/*
class Centinela : public Enemigo{
    private:
        int distanciaAtaque;
        int distanciaDisparo;
        void disparar(); //devuelve bala o nada ??????

    protected:
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};

class Murcielago : public Enemigo{
    private:
        int distanciaAtaque;
        int altura;
        int direccion = 0;
        bool haPegado;
    protected:
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};

class Reptante : public Enemigo{
    private:
        sf::RectangleShape esqIzq;
        sf::RectangleShape esqDcha;
        int direccion;
    protected:
        void update(sf::RectangleShape& player, float delta);
        void render(sf::RenderWindow& entrada, float porcentaje);   
};*/

#endif
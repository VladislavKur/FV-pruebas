#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player/Player.h>

#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo{
    public:
        Enemigo(sf::Texture tex, float x, float y);
        ~Enemigo();
        virtual void update(Player& player, float delta);
        virtual void render(sf::WindowsRender& entrada, float porcentaje);

    private:
        float posX, posY;
        float posXanterior, posYanterior;
        float diffX, diffY;
        float velocidad;
        int modo;
        sf::RectangleShape cuerpo;
        sf::Clock relojAnim;
        void actualizarPosicion(float x, float y);
}

class Centinela : public Enemigo{
    private:
        int distanciaAtaque;
        int distanciaDisparo;
        void disparar(); //devuelve bala o nada ??????

    protected:
        void update(Player& player, float delta);
        void render(sf::WindowsRender& entrada, float porcentaje);   
}

class Murcielago : public Enemigo{
    private:
        int distanciaAtaque;
        //int altura;
        bool haPegado;
    protected:
        void update(Player& player, float delta);
        void render(sf::WindowsRender& entrada, float porcentaje);   
}

class Reptante : public Enemigo{
    private:
        sf::RectangleShape esqIzq;
        sf::RectangleShape esqDcha;
        int direccion;
    protected:
        void update(Player& player, float delta);
        void render(sf::WindowsRender& entrada, float porcentaje);   
}

#endif
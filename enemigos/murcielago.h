#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MURCIELAGO_H
#define MURCIELAGO_H

class Murcielago{

    public:
        Murcielago(sf::Texture& tex);
        Murcielago(sf::Texture& tex,int x, int y);
        void update(sf::Sprite& entrada);
        void render(sf::RenderWindow& entrada, float porcentaje);
    private:
        void actualizarPosicion(float entradaX, float entradaY);
        float posX;
        float posY;
        float posXanterior;
        float posYanterior;
        float diffX;
        float diffY;
        float velocidad = 0.0001;
        int modo;
        //0: colgado 1:cayendo(diagonal-parabola) 2:recto
        sf::Sprite cuerpo;
        static const int altura = 500;
        static const int distanciaAcercamiento = 200;
        //static const int distanciaDisparo = 100;
        

};

#endif

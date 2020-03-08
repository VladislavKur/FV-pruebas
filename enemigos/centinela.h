#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef CENTINELA_H
#define CENTINELA_H

class Centinela{

    public:
        Centinela(sf::Texture& tex);
        Centinela(sf::Texture& tex,int x, int y);
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
        float velocidad = 0.001;
        int modo;
        //modo: 0 quieto, modo: 1 caminar, modo: 2 matar
        sf::Sprite cuerpo;
        static const int distanciaAcercamiento = 200;
        static const int distanciaDisparo = 100;

};

#endif

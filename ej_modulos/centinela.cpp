#include "centinela.h"

Centinela::Centinela(sf::Texture& tex){
    cuerpo.setTexture(tex);
    posX = 0.0;
    posY = 0.0;
    modo = 0;
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(posX, posY);

};

Centinela::Centinela(sf::Texture& tex, int x, int y){
    posX = x;
    posY = y;
    modo = 0;
    cuerpo.setTexture(tex);
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(x, y);
    

};

void Centinela::update(sf::Sprite entrada){

    float diffX = fabs(entrada.getPosition().x - posX);

    switch(modo){

        case(0): //está quieto


        break;

    }


};
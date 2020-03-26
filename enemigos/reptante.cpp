#include "reptante.h"


Reptante::Reptante(sf::Texture& tex, float x, float y) : Enemigo(tex,x,y){
    /*posX = x;
    posY = y;
    diffX= 0.0;
    diffY= 0.0;
    posXanterior = x;
    posYanterior = y;*/
    modo = 0;
    //cuerpo.setTexture(tex);
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(x, y);

    esqIzq.setOrigin(75 / 2, 75 / 2);
    esqDcha.setOrigin(75 / 2, 75 / 2);

    esqIzq.setRotation(34.825f);
    esqDcha.setRotation(55.175f);

    esqIzq.setPosition(x,y);
    esqDcha.setPosition(x,y);

    esqIzq.setFillColor(sf::Color(sf::Uint32 (255)));
    esqIzq.setFillColor(sf::Color(sf::Uint32 (120)));
};

void Reptante::update(sf::RectangleShape& entrada, float delta){
///las colisiones
};

void Reptante::render(sf::RenderWindow &entrada, float porcentaje){
    cuerpo.setPosition(
        posXanterior + diffX*porcentaje,
        posYanterior + diffY*porcentaje );

    entrada.draw(cuerpo);
}
#include "enemigo.h"


void Reptante::update(sf::RectangleShape& entrada, float delta){
///las colisiones

};

void Reptante::render(sf::RenderWindow &entrada, float porcentaje){
    cuerpo.setPosition(
        posXanterior + diffX*porcentaje,
        posYanterior + diffY*porcentaje );

    
    entrada.draw(cuerpo);
}
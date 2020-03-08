#include "centinela.h"

Centinela::Centinela(sf::Texture& tex){
    cuerpo.setTexture(tex);
    posX = 0.0;
    posY = 0.0;
    posXanterior = 0.0;
    posYanterior = 0.0;
    diffX = 0.0;
    diffY = 0.0;
    modo = 0;
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(posX, posY);

};

Centinela::Centinela(sf::Texture& tex, int x, int y){
    posX = x;
    posY = y;
    diffX= x;
    diffY= y;
    posXanterior = x;
    posYanterior = y;
    modo = 0;
    cuerpo.setTexture(tex);
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(x, y);
};

void Centinela::actualizarPosicion(float entradaX, float entradaY){

    posXanterior = posX;
    posYanterior = posY;
    posX += entradaX;
    posY += entradaY;
    diffX = posX - posXanterior;
    diffY = posY - posYanterior;

};

void Centinela::update(sf::RectangleShape& entrada){

    float posJugador = entrada.getPosition().x;

    float local_diffX = posJugador - posX;
    float local_diffabs = abs(diffX);

    diffX = 0; //inicialmente no se mueve
    diffY = 0; //inicialmente no se mueve

    bool cambio; //no nos cambiamos de modo por defecto
    do{
        cambio = false;//no nos cambiamos de modo por defecto
        switch(modo){

            case(0): //está quieto
                if(local_diffabs < distanciaAcercamiento){//si está lo suficientemente cerca, cambiamos
                    modo = 1;
                    cambio = true;
                }
                if(local_diffabs < distanciaDisparo){//si está lo suficientemente cerca, cambiamos
                    modo = 2;
                    cambio = true;
                }
            break;
            case(1):
                if(local_diffabs < distanciaDisparo){//si está lo suficientemente cerca, cambiamos
                    modo = 2;
                    cambio = true;
                }
                else{//si no cambiamos, actualiza su posicion
                   actualizarPosicion((local_diffX/local_diffabs)*velocidad,0);                  
                }
                
            break;
            case(2):
                if(local_diffabs > distanciaDisparo){//si está lo suficientemente lejos, cambiamos
                    modo = 1;
                    cambio = true;
                } 
                else{//DISPARA!!!! necesitamos el trabajo de vermivlad

                    ////WIP
                    ////WIP
                    ////WIP
                    ////WIP
                    ////WIP
                    entrada.setScale(0.5,0.5);

                }
                
            break;

        }
    }while(cambio); //si cambiamos de modo, volvemos a iterar en el bucle

};

void Centinela::render(sf::RenderWindow &entrada, float porcentaje){
    cuerpo.setPosition(
        posXanterior + diffX*porcentaje,
        posYanterior + diffY*porcentaje);
    
    entrada.draw(cuerpo);
}
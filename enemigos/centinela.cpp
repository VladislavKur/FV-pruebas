#pragma once
#include "centinela.h"

void Centinela::update(sf::RectangleShape& entrada, float delta){

    float posJugador = entrada.getPosition().x;

    float local_diffX = posJugador - posX;
    float local_diffabs = abs(local_diffX);

    diffX = 0; //inicialmente no se mueve
    diffY = 0; //inicialmente no se mueve

    bool cambio; //no nos cambiamos de modo por defecto
    do{
        cambio = false;//no nos cambiamos de modo por defecto
        switch(modo){

            case(0): //está quieto
                if(local_diffabs < distanciaAtaque){//si está lo suficientemente cerca, cambiamos
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
        posYanterior + diffY*porcentaje );

    
    entrada.draw(cuerpo);
}
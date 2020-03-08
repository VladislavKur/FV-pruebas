#include "murcielago.h"

Murcielago::Murcielago(sf::Texture& tex){
    cuerpo.setTexture(tex);
    posX = 1100.0;
    posY = 100.0;
    posXanterior = 0.0;
    posYanterior = 0.0;
    diffX = 0.0;
    diffY = 0.0;
    modo = 0;
    cuerpo.setOrigin(75 / 2, 75 / 2);
    cuerpo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
    cuerpo.setPosition(posX, posY);

};

Murcielago::Murcielago(sf::Texture& tex, int x, int y){
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
    cuerpo.setPosition(x+100, y+100);
};

void Murcielago::update(sf::Sprite& entrada){

    float posJugador = entrada.getPosition().x;

    float diffX = posJugador - posX;
    float diffabs = abs(diffX);

    bool cambio; //no nos cambiamos de modo por defecto
    do{
        cambio = false;//no nos cambiamos de modo por defecto
        switch(modo){

            case(0): //está quieto
                if(diffabs < distanciaAcercamiento){//si está lo suficientemente cerca, cambiamos
                    modo = 1;
                    cambio = true;
                }
                
            break;
            case(1)://diagonal
                if(posY == altura){
                   modo = 2;
                   cambio = true;
                }
                else{
                    diffX = (diffX/diffabs)*velocidad;//diffX/diffabs nos da el signo //(si está a la izquierda es negativo)
                    diffY = (diffX/diffabs)*velocidad; //diffX y diffY es lo que se tienen que mover
                    posXanterior = posX; //guardamos la anterior
                    posYanterior = posY; //guardamos la anterior
                    posX += diffX; //actualizamos la futura
                }
                                
            break;
            case(2): //recto
                diffX = (diffX/diffabs)*velocidad;//diffX/diffabs nos da el signo 
                                                        //(si está a la izquierda es negativo)
                diffY = 0; //diffX y diffY es lo que se tienen que mover
                posXanterior = posX; //guardamos la anterior
                posYanterior = posY; //guardamos la anterior
                posX += diffX; //actualizamos la futura
            break;

        }
        
    }while(cambio); //si cambiamos de modo, volvemos a iterar en el bucle

};

void Murcielago::render(sf::RenderWindow &entrada, float porcentaje){
    //cuerpo.move(diffX/porcentaje,diffY/porcentaje);
    if(diffX/porcentaje <= posX && diffY/porcentaje <= posY){
        cuerpo.setPosition(posX,posY);
    }
    else{
      
        posXanterior = diffX/porcentaje;
        posYanterior = diffY/porcentaje;
        cuerpo.setPosition(posXanterior,posYanterior);
    }
    
    entrada.draw(cuerpo);

    /////HABLAR CON FIDEL
    //renderizar con getPosition() en vez de move()
}
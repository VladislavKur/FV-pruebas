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
    cuerpo.setPosition(x, y);
};

void Murcielago::actualizarPosicion(float entradaX, float entradaY){

    posXanterior = posX;
    posYanterior = posY;
    posX += entradaX;
    posY += entradaY;
    diffX = posX - posXanterior;
    diffY = posY - posYanterior;

};

void Murcielago::update(sf::Sprite& entrada){

    float posJugadorX = entrada.getPosition().x;
    float posJugadorY = entrada.getPosition().y;

    float local_diffX = posJugadorX - posX;
    float local_diffY = posJugadorY - posY;
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
                
            break;
            case(1)://diagonal
                if(posY == altura){
                   modo = 2;
                   cambio = true;
                }
                else{
                    actualizarPosicion((local_diffX/local_diffabs)*velocidad,0);     
                }
                                
            break;
            case(2): //recto
                actualizarPosicion((local_diffX/local_diffabs)*velocidad,(local_diffY/local_diffabs)*velocidad);     
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
        //pasos = pruebaXa +(pruebaX -pruebaXa)*delta;
        posXanterior += diffX/porcentaje;
        posYanterior += diffY/porcentaje;
        cuerpo.setPosition(posXanterior + (posX-posXanterior)* porcentaje, posYanterior + (posY-posYanterior)*porcentaje);
    }
    
    entrada.draw(cuerpo);

    /////HABLAR CON FIDEL
    //renderizar con getPosition() en vez de move()
}
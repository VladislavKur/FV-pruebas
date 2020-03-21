#include "murcielago.h"


void Murcielago::update(sf::RectangleShape& entrada, float delta){

    float posJugadorX = entrada.getPosition().x;
    float posJugadorY = entrada.getPosition().y;

    float local_diffX = posJugadorX - posX;
    float local_diffY = posJugadorY - posY;
    float local_diffabsX = abs(local_diffX);
    float local_diffabsY = abs(local_diffY);

    diffX = 0; //inicialmente no se mueve
    diffY = 0; //inicialmente no se mueve


    bool cambio; //no nos cambiamos de modo por defecto
    do{
        cambio = false;//no nos cambiamos de modo por defecto
        switch(modo){

            case(0): //está quieto
                if(local_diffabsX < distanciaAtaque){//si está lo suficientemente cerca, cambiamos
                    modo = 1;
                    cambio = true;
                }
            break;
            case(1)://diagonal
                if(local_diffY <= altura){
                   modo = 2;
                   cambio = true;
                }
                else{

                    float movimientoSuaveX = (local_diffX/local_diffabsX)*velocidad*delta;
                    float movimientoSuaveY = (local_diffY/local_diffabsY)*velocidad*delta;

                    actualizarPosicion(movimientoSuaveX,movimientoSuaveY); 
                }
                
            break;
            case(2): //recto

                if(direccion == 0)
                    direccion = local_diffX/local_diffabsX;

                actualizarPosicion(direccion*velocidad,0);     
            break;

        }
        
    }while(cambio); //si cambiamos de modo, volvemos a iterar en el bucle

};

void Murcielago::render(sf::RenderWindow &entrada, float porcentaje){
    cuerpo.setPosition(
        posXanterior + diffX*porcentaje,
        posYanterior + diffY*porcentaje );
    
    entrada.draw(cuerpo);

    /////HABLAR CON FIDEL
    //renderizar con getPosition() en vez de move()
}
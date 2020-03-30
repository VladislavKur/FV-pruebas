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

    /*esqIzq.setOrigin(75 / 2, 75 / 2);
    esqDcha.setOrigin(75 / 2, 75 / 2);

    esqIzq.setRotation(34.825f);
    esqDcha.setRotation(55.175f);

    esqIzq.setPosition(x,y);
    esqDcha.setPosition(x,y);

    esqIzq.setFillColor(sf::Color(sf::Uint32 (255)));
    esqIzq.setFillColor(sf::Color(sf::Uint32 (120)));*/
    
    
}

/*void Reptante::update(sf::RectangleShape& entrada, float delta){
///las colisiones
}*/

void Reptante::update(float deltaTime, Plataforma plataforma, Plataforma suelo){
    Vector2f gp = cuerpo.getPosition();
    FloatRect gbb = cuerpo.getGlobalBounds();
    
    coliAbajo.left = gp.x - gbb.width/2 + 25;
    coliAbajo.top = gp.y + gbb.height/2;
    coliAbajo.width = gbb.width-50;
    coliAbajo.height = 6;
    
    coliIzquierda.left = gp.x - gbb.width/2+12;
    coliIzquierda.top = gp.y - gbb.height/2 + 25 ;
    coliIzquierda.width = gbb.width/2-15;
    coliIzquierda.height = gbb.height -25;

    coliDerecha.left = gp.x+5;
    coliDerecha.top = gp.y - gbb.height/2 +25;
    coliDerecha.width = gbb.width/2 -20;
    coliDerecha.height = gbb.height -25;

    coliArriba.left = gp.x - gbb.width/2 + 20;
    coliArriba.top = gp.y-gbb.height/2 +25;
    coliArriba.width = gbb.width - 40;
    coliArriba.height = 5;


    //Moverse a la derecha si la plataforma lo permite
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      if(!coliDerecha.intersects(plataforma.getBody().getGlobalBounds()))
        moveRight(deltaTime);
      }
    //Moverse a la izquierda si la plataforma lo permite
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      if(!coliIzquierda.intersects(plataforma.getBody().getGlobalBounds()))
        moveLeft(deltaTime);
      }

}

void Reptante::moveRight(float deltaTime){

      cuerpo.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      cuerpo.setScale(1, 1);
      cuerpo.move(500*deltaTime, 0);

}
void Reptante::moveLeft(float deltaTime){

     cuerpo.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
     cuerpo.setScale(-1, 1);
     cuerpo.move(-500*deltaTime, 0);


}

void Reptante::render(sf::RenderWindow &entrada, float porcentaje){
    cuerpo.setPosition(
        posXanterior + diffX*porcentaje,
        posYanterior + diffY*porcentaje );

    entrada.draw(cuerpo);
}
#include <SFML/Graphics.hpp>
#include <iostream>



#include "include/config.h"


#define kVel 5

int main() {
  /////////////
  ////START////
  /////////////


  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(320, 240);

  float jumpSpeed=0;
  float yInicial=sprite.getPosition().y;
  bool saltando=false;

  float jumpHeight=75*1.5;

  float deltaTime = 0;
  sf::Clock clock;

  //////////////////
  ////BUCLE////////
  ////////////////
  while (window.isOpen()) {
    
    //////////////
    ////INPUT/////
    /////////////
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {
          

        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window.close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
        default: break;
      }
    }


    ////////////
    ///UPDATE///
    ////////////
    deltaTime = clock.restart().asSeconds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      sprite.setScale(1, 1);
      sprite.move(0.05, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          sprite.setScale(-1, 1);
          sprite.move(-0.05, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){

          if(!saltando){
            saltando=true;
            jumpSpeed = -sqrtf(2.0f * 981.0f * jumpHeight);
          }
          

    }

    if(sprite.getPosition().y>yInicial){
      jumpSpeed=0;
      sprite.setPosition( sf::Vector2f(sprite.getPosition().x,yInicial) );
      saltando=false;
    }
    
    if(saltando){
        
        jumpSpeed+=981.0f*deltaTime;

        

    }
    
    sprite.move(sf::Vector2f(0,jumpSpeed*deltaTime));
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"

#define kVel 1

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1200, 1200), "P0. Fundamentos de los Videojuegos. DCCIA");

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
  sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  sprite.setPosition(100, 100);

  int modoReptante = 0; //0: suelo, 1: paredD; 2: techo 3: paredI
  int direccion = 1; //1: reloj, -1: contrario

  //Bucle del juego
  while (window.isOpen()) {
    if(direccion == -1)
    modoReptante = 1;
    //switch movimiento del reptante
    switch(modoReptante){
      case 0: //suelo
            sprite.move(kVel*direccion, 0);
            if(sprite.getPosition().x == 1100 && direccion==1)
                modoReptante = 3;
            else
            {
                if(sprite.getPosition().y == 100 && direccion==-1)
                    modoReptante = 1;
            }
            
      break;
      case 1: //paredIzq
            sprite.move(0, -kVel*direccion);
            if(sprite.getPosition().y == 100 && direccion==1)
                modoReptante = 0;
            else
            {
                if(sprite.getPosition().x == 100 && direccion==-1)
                    modoReptante = 2;
            }
      break;
      case 2://Techo
            sprite.move(-kVel*direccion, 0);
            if(sprite.getPosition().x == 100 && direccion==1)
                modoReptante = 1;
            else
            {
                if(sprite.getPosition().y == 100 && direccion==-1)
                    modoReptante = 3;
            }
      break;
      case 3://pared Dereecha
            sprite.move(0, kVel*direccion);
            if(sprite.getPosition().y == 800 && direccion==1)
                modoReptante = 2;
            else
            {
                if(sprite.getPosition().x == 1100 && direccion==-1)
                    modoReptante = 1;
            }
      break;
    }
    
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {
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
      }
    }

    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}
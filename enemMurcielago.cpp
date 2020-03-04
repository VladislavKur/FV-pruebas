#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"

#define kVel 0.001

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1200, 1200), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  /////////////
  ///Enemigo///
  /////////////

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite enemigo(tex);

  enemigo.setOrigin(75 / 2, 75 / 2);
  enemigo.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  enemigo.setPosition(1100, 100);
int cont = 1;
  
  //Bucle del juego
  while (window.isOpen()) {
    enemigo.move(kVel-1, kVel+1);
    //enemigo.setPosition(enemigo.getPosition().x-cont,enemigo.getPosition().y+cont);
    cont++;
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {
      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
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
    window.draw(enemigo);
    window.display();
  }

  return 0;
}
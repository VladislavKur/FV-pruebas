#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "enemigos/murcielago.h"

#define kVel 300
#define UPDATE_TICK_TIME 15/1000

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1200, 1200), "P0. Fundamentos de los Videojuegos. DCCIA");
  window.setFramerateLimit(60);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  /////////////
  ///Enemigo///
  /////////////
  Murcielago *enemigo = new Murcielago(tex,1,0);
  //Murcielago::Murcielago enemigo(tex,1100,100);
  //Y creo el spritesheet a partir de la imagen anterior
  /*sf::Sprite jugador(tex);
  jugador.setOrigin(75 / 2, 75 / 2);
  jugador.setTextureRect(sf::IntRect(1 * 75, 1 * 75, 75, 75));
  jugador.setPosition(100, 600);*/
  
  sf::RectangleShape cuerpoMueve(sf::Vector2f(50.0f, 70.0f));
  cuerpoMueve.setFillColor(sf::Color(0,255,0));
  cuerpoMueve.setPosition(sf::Vector2f(100,600));

  //float velocidadX = kVel;
  
  sf::Clock updateClock;
  float delta;

  float pasos = 0;
  float pruebaX = 0;
  float pruebaXa = 0;
  //Bucle del juego
  while (window.isOpen()) {
    if(updateClock.getElapsedTime().asMilliseconds()>UPDATE_TICK_TIME){
      delta = updateClock.restart().asMilliseconds();
      enemigo->update(cuerpoMueve);

    }
  
    sf::Event evnt;
    while (window.pollEvent(evnt)) {

      switch (evnt.type){
      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (evnt.key.code) {
            //Tecla ESC para salir
            case sf::Keyboard::Escape:
            window.close();
            break;

            //Cualquier tecla desconocida se imprime por pantalla su código
            default:
            std::cout << evnt.key.code << std::endl;
            break;
        }
      }
    }

    window.clear();
    //pasos = pruebaXa +(pruebaX -pruebaXa)*delta;
    cuerpoMueve.move(kVel*(delta/UPDATE_TICK_TIME),0);
    enemigo->render(window, delta/UPDATE_TICK_TIME);
    window.draw(cuerpoMueve);
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>

#include "enemigos/reptante.h"


#define kVel 1
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

  float x = 200.0f;
  float y = 150.0f;
  Reptante *enemigo = new Reptante(tex);

  //Plataforma plataforma1(nullptr, sf::Vector2f(100.0f,1000.0f),sf::Vector2f(500.0f,200.0f));
  sf::RectangleShape cuerpoMueve(sf::Vector2f(50.0f, 70.0f));
  cuerpoMueve.setFillColor(sf::Color(0,255,0));
  cuerpoMueve.setPosition(sf::Vector2f(-100,600));

  sf::Clock updateClock;
  float delta;

  //Bucle del juego
  while (window.isOpen()) {
    if(updateClock.getElapsedTime().asMilliseconds()>UPDATE_TICK_TIME){
      delta = updateClock.restart().asMilliseconds();
      enemigo->update(cuerpoMueve, delta);

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
        default: 
        break;
      }
    }

    //enemigo->update(,delta);
    //plataforma1.getCollider().checkCollision(enemigo->getCollider(),1.0f);

    window.clear();
    cuerpoMueve.move(kVel*(delta/UPDATE_TICK_TIME),0);
    enemigo->render(window, delta/UPDATE_TICK_TIME);
    window.draw(cuerpoMueve);
    window.display();
  }

  return 0;
}
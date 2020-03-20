#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


#include "centinela.h"

#define kVel 900
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
  //////////////
  ///BLOQUE////
  /////////////

  
  sf::RectangleShape cuerpoMueve(sf::Vector2f(50.0f, 70.0f));
  cuerpoMueve.setFillColor(sf::Color(0,255,0));
  cuerpoMueve.setPosition(sf::Vector2f(100,600));
  

  float x = 1100.0;
  float y = 600.0;
  Centinela *maloso = new Centinela(tex,x,y);

  //Bucle del juego

  sf::Clock updateClock;
  float delta;
  while (window.isOpen()) {
    /////////////////////////////////////////////
    //LO PRIMERO ES LA COMPROBACION DE UPDATEAR//
    /////////////////////////////////////////////
    if(updateClock.getElapsedTime().asMilliseconds()>UPDATE_TICK_TIME){ //si hay que actualizar, actualiza
      delta = updateClock.restart().asMilliseconds();
      maloso->update(cuerpoMueve, delta);

    }

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
        default:
        break;
      }
    
    }
    //////////////////////////
    //LO SEGUNDO ES RENDERIZAR
    //////////////////////////
    window.clear();
    cuerpoMueve.move(kVel*(delta/UPDATE_TICK_TIME),0);
    maloso->render(window, delta/UPDATE_TICK_TIME);
    window.draw(cuerpoMueve);
    window.display();
  }

  return 0;
}
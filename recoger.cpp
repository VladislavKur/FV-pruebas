#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player/Player.h"



#define kVel 5

bool colision(sf::RectangleShape objeto1, sf::RectangleShape objeto2){
    if(objeto1.getGlobalBounds().intersects(objeto2.getGlobalBounds())){
        return true;
    }
    return false;
}


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
  
  std::cout << "Pulsa E para recoger el rectangulo verde" << std::endl;
 
  Plataforma plataforma1(nullptr,sf::Vector2f(400,40),sf::Vector2f(200, 400) );  
  Plataforma plataforma2(nullptr,sf::Vector2f(1000,5),sf::Vector2f(0,500) );  

  Player player(&tex, sf::Vector2u(40,19),0.33f);

  
  float deltaTime = 0;
  sf::Clock clock;

  sf::RectangleShape item(sf::Vector2f(25.0f, 17.0f));
  item.setFillColor(sf::Color(0,255,0));
  item.setPosition(sf::Vector2f(200,200));
 sf::View view(sf::Vector2f(player.getBody().getPosition().x, player.getBody().getPosition().y), sf::Vector2f( 640.0f, 480.0f));

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

      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:

        switch (event.key.code) {
          
        case sf::Keyboard::Escape:
          window.close();
          break;
        case sf::Keyboard::Space:

        break;

        default:
          break;
        }
        default: break;
      }
    }


    ////////////
    ///UPDATE///
    ////////////
    deltaTime = clock.restart().asSeconds();

    player.update(deltaTime,plataforma1, plataforma2);

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::E) && colision(player.getBody(),item)){
        item.setSize(sf::Vector2f(0,0));
        player.setSaltos();
        item.setPosition(-500,-500); //lejos de la accion         
        player.obtenerPU_SaltoDoble();              
    }
 
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    player.draw(window);
    window.draw(item);
    window.display();
  }

  return 0;
}
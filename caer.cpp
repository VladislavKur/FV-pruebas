#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player/Player.h"
#include "Plataforma/Plataforma.h"


#define kVel 5

int main() {
  /////////////
  ////START////
  /////////////

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }


  Player player(&tex, sf::Vector2u(6,4),0.33f);
  Plataforma plataforma1(nullptr,sf::Vector2f(400,40),sf::Vector2f(200, 400) );  
  Plataforma plataforma2(nullptr,sf::Vector2f(1000,5),sf::Vector2f(0,500) );  




  float deltaTime = 0;
  sf::Clock clock;




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
          

        case sf::Keyboard::Right:
          break;

        case sf::Keyboard::Left:
          
          case sf::Keyboard::Space:
          break;
        case sf::Keyboard::Escape:
          window.close();
          break;

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

    player.update(deltaTime, plataforma1, plataforma2);
  
  
    //plataforma1.getCollider().checkCollision( .getCollider(),0.0f);
    

    view.setCenter(player.getBody().getPosition());
    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    
    window.setView(view);

    player.draw(window);
    plataforma1.Draw(window);
    plataforma2.Draw(window);


    window.display();
    }
  

  return 0;
}
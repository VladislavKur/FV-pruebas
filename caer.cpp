#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player/Player.h"
#include "Plataforma/Plataforma.h"

using namespace sf;

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
  Plataforma plataforma1(nullptr,sf::Vector2f(400,40),sf::Vector2f(200, 300) );  
  Plataforma plataforma2(nullptr,sf::Vector2f(1000,5),sf::Vector2f(0,500) );  


     Vector2f gp = player.getBody().getPosition();
    FloatRect gbb = player.getBody().getGlobalBounds();

  float deltaTime = 0;
  sf::Clock clock;

  RectangleShape coliAbajoVisible;
  RectangleShape coliArribaVisible;
  RectangleShape coliIzquierdaVisible;
  RectangleShape coliDerechaVisible;


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
    

    coliAbajoVisible.setPosition(Vector2f(player.coliAbajo.left, player.coliAbajo.top));
    coliAbajoVisible.setSize(Vector2f(player.coliAbajo.width, player.coliAbajo.height));
    coliAbajoVisible.setFillColor(Color(255,255,255,128));

    coliArribaVisible.setPosition(Vector2f(player.coliArriba.left, player.coliArriba.top));
    coliArribaVisible.setSize(Vector2f(player.coliArriba.width, player.coliArriba.height));
    coliArribaVisible.setFillColor(Color(255,255,0, 128));

    coliDerechaVisible.setPosition(Vector2f(player.coliDerecha.left, player.coliDerecha.top));
    coliDerechaVisible.setSize(Vector2f(player.coliDerecha.width, player.coliDerecha.height));
    coliDerechaVisible.setFillColor(Color(255,0,0,128));

    coliIzquierdaVisible.setPosition(Vector2f(player.coliIzquierda.left, player.coliIzquierda.top));
    coliIzquierdaVisible.setSize(Vector2f(player.coliIzquierda.width, player.coliIzquierda.height));
    coliIzquierdaVisible.setFillColor(Color(0,255,0,128));
    
   
    deltaTime = clock.restart().asSeconds();

    player.update(deltaTime, plataforma1, plataforma2);
  
    Collider plat1col=plataforma1.getCollider();
    Collider playercol = player.getCollider();
  
    player.getCollider().checkCollision(plat1col ,0.0f);
    

    view.setCenter(player.getBody().getPosition());
    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    
    window.setView(view);

    player.draw(window);
    plataforma1.Draw(window);
    plataforma2.Draw(window);
    window.draw(coliAbajoVisible);
    window.draw(coliArribaVisible);
    window.draw(coliDerechaVisible);
    window.draw(coliIzquierdaVisible);

    window.display();
    }
  

  return 0;
}
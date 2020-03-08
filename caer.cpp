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


  sf::RectangleShape plataforma(sf::Vector2f(400,40));
  sf::RectangleShape suelo(sf::Vector2f(1000,5));
  

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);

  //Le pongo el centroide donde corresponde
 
  //Cojo el sprite que me interesa por defecto del sheet


  // Lo dispongo en el centro de la pantalla
  

  float jumpSpeed=0;
  //float yInicial=sprite.getPosition().y;
  //bool saltando=false;
  bool enTierra=false;

  float jumpHeight=75*2;

  float deltaTime = 0;
  sf::Clock clock;

  sprite.setOrigin(75 / 2, 75 / 2);
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  sprite.setPosition(320, 40);

  plataforma.setFillColor(sf::Color(0,0,128));
  plataforma.setPosition(200, sprite.getPosition().y+300 );


  suelo.setFillColor(sf::Color(255,0,0));
  suelo.setPosition(0,470);


  sf::View view(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y), sf::Vector2f( 640.0f, 480.0f));

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
          

        //Mapeo del cursor
        case sf::Keyboard::Right:
          break;

        case sf::Keyboard::Left:
          
          case sf::Keyboard::Space:
          break;
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
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
    deltaTime = clock.restart().asSeconds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      sprite.setScale(1, 1);
      sprite.move(500*deltaTime, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          sprite.setScale(-1, 1);
          sprite.move(-500*deltaTime, 0);
    }

  if(sprite.getGlobalBounds().intersects(plataforma.getGlobalBounds()) ||
   sprite.getGlobalBounds().intersects(suelo.getGlobalBounds()) ){
    enTierra=true;
    jumpSpeed=0;
    //std::cout<<plataforma.getGlobalBounds().intersects(sprite.getGlobalBounds()) << std::endl;
  }else enTierra=false;
    
  

    /*if(sprite.getPosition().y>yInicial){
      jumpSpeed=0;
      sprite.setPosition( sf::Vector2f(sprite.getPosition().x,yInicial) );
      saltando=false;
    }*/
    
    if(!enTierra){
      jumpSpeed+=981.0f*deltaTime;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
      if(enTierra){
        enTierra=false;
        jumpSpeed = -sqrtf(2.0f * 981.0f * jumpHeight);
      }
    }
    
    //Caída
    sprite.move(sf::Vector2f(0,jumpSpeed*deltaTime));
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    view.setCenter(sprite.getPosition());
    window.setView(view);

    window.draw(sprite);
    window.draw(plataforma);
    window.draw(suelo);

    window.display();
    }else{



       jumpSpeed=0;
       
        sprite.setOrigin(75 / 2, 75 / 2);
        sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
        sprite.setPosition(320, 40);

       

        plataforma.setFillColor(sf::Color(0,0,128));
        plataforma.setPosition(200, sprite.getPosition().y+300 );


        suelo.setFillColor(sf::Color(255,0,0));
        suelo.setPosition(0,470);

    }
  }

  return 0;
}
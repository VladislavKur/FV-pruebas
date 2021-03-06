#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player/Player.h"
#include "Bullet/Bullet.h"


#define kVel 5
#define maxBullets 64

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

  

  sf::RectangleShape plataforma(sf::Vector2f(400,40));
  sf::RectangleShape suelo(sf::Vector2f(1000,5));
  
  sf::Sprite sprite;

  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  Bullet* bullets[maxBullets];
  for(int i=0 ; i<maxBullets ; i++){
    bullets[i]=NULL;
  }

  Player player(&tex, sf::Vector2u(40,19),0.33f);

  float deltaTime = 0;
  sf::Clock clock;

  float cooldown=0;

  Plataforma plataforma1(nullptr,sf::Vector2f(400,40),sf::Vector2f(200, 400) );  
  Plataforma plataforma2(nullptr,sf::Vector2f(1000,5),sf::Vector2f(0,500) );  

  plataforma.setFillColor(sf::Color(0,0,128));
  plataforma.setPosition(200, sprite.getPosition().y+300 );

  sf::RectangleShape item(sf::Vector2f(25.0f, 17.0f));
  item.setFillColor(sf::Color(0,255,0));
  item.setPosition(sf::Vector2f(200,200));

  suelo.setFillColor(sf::Color(255,0,0));
  suelo.setPosition(0,470);

  std::cout << "Usa las flechas para moverte y SPACE para saltar" << std::endl;
  std::cout << "Pulsa E para recoger el rectangulo verde (arma)" << std::endl;
  std::cout << "Una vez recogida el arma, pulsa D para disparar" << std::endl;

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

        default: break;
        }
        default: break;
      }
    }


    ////////////
    ///UPDATE///
    ////////////
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
    deltaTime = clock.restart().asSeconds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        for(int i=0 ; i<maxBullets ; i++){
          if(bullets[i]==NULL && cooldown<=0 && player.getArma()==1){
            bullets[i]=new Bullet( player.getBody().getPosition().x , player.getBody().getPosition().y, (player.getBody().getScale().x > 0) );
            cooldown=750*deltaTime;
            break;
          }
        }
    }

    player.update(deltaTime, plataforma1, plataforma2);

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::E) && colision(player.getBody(),item)){
        item.setSize(sf::Vector2f(0,0));
        item.setPosition(-500,-500); //lejos de la accion   
        player.setArma(1);      
        player.obtenerPU_SaltoDoble();              
    }

    cooldown-=deltaTime;

    for(int i=0 ; i<maxBullets ; i++){
      if(bullets[i]!=NULL){
        bullets[i]->update(deltaTime);
        if(bullets[i]->lifetime<=0){
          delete bullets[i];
          bullets[i]=NULL;
        }
      }
    }
    
    

    /*if(sprite.getPosition().y>yInicial){
      jumpSpeed=0;
      sprite.setPosition( sf::Vector2f(sprite.getPosition().x,yInicial) );
      saltando=false;
    }*/
    
    
    

    ///////////////
    /////DRAW/////
    //////////////
    window.clear();
    view.setCenter(player.getBody().getPosition());
    window.setView(view);

    for (unsigned int i = 0; i < maxBullets; i++){
      if(bullets[i] != NULL){
        bullets[i]->draw(window);
      }
    }
    
    plataforma1.Draw(window);
    plataforma2.Draw(window);
    player.draw(window);
    window.draw(item);

    window.display();
    }else{



       
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
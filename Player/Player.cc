#include "Player.h"
#include <SFML/Graphics.hpp>

Player::~Player(){

}

Player::Player(sf::Texture* tex, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) 
: body(*tex) , animacion(tex,cantidadImagenes,SwitchTimeSprite){
    

    // 75 es el tamaño del sprite, cambiar
    body.setOrigin(75 / 2, 75 / 2);
    body.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

    //Quitar esto mas adelante
    body.setPosition(320, 40);

    jumpSpeed=0;
    jumpHeight=75*2;

    
}

void Player::update(float deltaTime, sf::RectangleShape plataforma, sf::RectangleShape suelo){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      body.setScale(1, 1);
      body.move(500*deltaTime, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          body.setScale(-1, 1);
          body.move(-500*deltaTime, 0);
    }

  if(body.getGlobalBounds().intersects(plataforma.getGlobalBounds()) ||
   body.getGlobalBounds().intersects(suelo.getGlobalBounds()) ){
    saltos=1;
    jumpSpeed=0;
    //std::cout<<plataforma.getGlobalBounds().intersects(sprite.getGlobalBounds()) << std::endl;
  }else saltos=0;

  if(saltos==0){
      jumpSpeed+=981.0f*deltaTime;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
      if(saltos!=0){
        saltos--;
        jumpSpeed = -sqrtf(2.0f * 981.0f * jumpHeight);
      }
    }
    
    //Caída
    body.move(sf::Vector2f(0,jumpSpeed*deltaTime));
}




void Player::draw(sf::RenderWindow& window){
    window.draw(body);
}

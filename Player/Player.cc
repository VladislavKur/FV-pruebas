
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Plataforma/Plataforma.h"
Player::~Player(){

}

Player::Player(sf::Texture* tex, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) 
: animacion(tex,cantidadImagenes,SwitchTimeSprite){
    
    body.setSize(sf::Vector2f(100.0f,100.0f));
    body.setTexture(tex);
    body.setOrigin(75 / 2, 75 / 2);  // 75 es el tamaño del sprite, cambiar
    body.setPosition(320, 40);//Quitar esto mas adelante

    
    saltos = 1;
    jumpSpeed=0;
    jumpHeight=75*2;

    
}

void Player::update(float deltaTime, Plataforma plataforma, Plataforma suelo){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))moveRight(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))moveLeft(deltaTime);

 if(body.getGlobalBounds().intersects(plataforma.getBody().getGlobalBounds()) ||
   body.getGlobalBounds().intersects(suelo.getBody().getGlobalBounds()) ){
    saltos = PU_saltoDoble ? 2 : 1;
    jumpSpeed=0;
   } else 
      jumpSpeed+=981.0f*deltaTime;

  //caer
    if(saltos==0){
       
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        saltar();
    }
    
    //Caída constante
    body.move(sf::Vector2f(0,jumpSpeed*deltaTime));
}

void Player::setSaltos(){
  
  //jumpHeight *= 2;
  saltos+= 100;
}




void Player::draw(sf::RenderWindow& window){
    window.draw(body);
}
void Player::moveRight(float deltaTime){

      body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      body.setScale(1, 1);
      body.move(500*deltaTime, 0);

}
void Player::moveLeft(float deltaTime){

     body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
     body.setScale(-1, 1);
     body.move(-500*deltaTime, 0);


}
void Player::saltar(){
  if(saltos!=0){
        
        jumpSpeed = -sqrtf(2.0f * 981.0f * jumpHeight);
        std::cout<<saltos<<std::endl;
        saltos--;
      }
}


void Player::obtenerPU_SaltoDoble(){
  PU_saltoDoble=true;
}

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Plataforma/Plataforma.h"
Player::~Player(){

}

Player::Player(sf::Texture* tex, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) 
: animacion(tex,cantidadImagenes,SwitchTimeSprite){
    
    arma=0;
    body.setSize(sf::Vector2f(100.0f,100.0f));
    body.setTexture(tex);
    body.setOrigin(75 / 2, 75 / 2);  // 75 es el tamaño del sprite, cambiar
    body.setPosition(320, 40);//Quitar esto mas adelante

    body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
    saltos = 1;
    jumpSpeed=0;
    jumpHeight=75*2;

    
}

void Player::update(float deltaTime, Plataforma plataforma, Plataforma suelo){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))moveRight(deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))moveLeft(deltaTime);
    float izq = body.getGlobalBounds().left;

 if(plataforma.getBody().getGlobalBounds().intersects(body.getGlobalBounds()) ||
   suelo.getBody().getGlobalBounds().intersects(body.getGlobalBounds()) ){
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
    body.move(0,jumpSpeed*deltaTime);
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
        std::cout<< "Saltos: " << saltos<<std::endl;
        saltos--;
      }
}


void Player::obtenerPU_SaltoDoble(){
  PU_saltoDoble=true;
}

void Player::setArma(int p_arma){
  arma = p_arma;
}
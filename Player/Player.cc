#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::~Player(){

}

Player::Player(sf::Texture* tex, sf::Vector2u cantidadImagenes, float SwitchTimeSprite) 
: body(*tex) , animacion(tex,cantidadImagenes,SwitchTimeSprite){
    
    arma=0;

    // 75 es el tamaño del sprite, cambiar
    body.setOrigin(75 / 2, 75 / 2);
    body.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

    //Quitar esto mas adelante
    body.setPosition(320, 40);

    jumpSpeed=0;
    jumpHeight=75*2;

    
}

void Player::update(float deltaTime, sf::RectangleShape plataforma, sf::RectangleShape suelo){
    //moverse a la derecha
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
      //Escala por defecto
      body.setScale(1, 1);
      body.move(500*deltaTime, 0);
    }

    //moverse a la izquierda
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      body.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          body.setScale(-1, 1);
          body.move(-500*deltaTime, 0);
    }

  //dejar de caer al tocar una plataforma
  if(body.getGlobalBounds().intersects(plataforma.getGlobalBounds()) ||
   body.getGlobalBounds().intersects(suelo.getGlobalBounds()) ){
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

void Player::draw(sf::RenderWindow& window){
    window.draw(body);
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
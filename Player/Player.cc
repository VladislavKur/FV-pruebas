
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Plataforma/Plataforma.h"

using namespace sf;
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

    PU_saltoDoble=false;
    PU_slowhits=false;
    PU_velocidad=false;
    vida = 2;
    saltos = 1;
    jumpSpeed=0;
    jumpHeight=75*2;

    auxSaltos = true;
    cooldownSalto = 0;
    
}

void Player::update(float deltaTime, Plataforma plataforma, Plataforma suelo){
    Vector2f gp = body.getPosition();
    FloatRect gbb = body.getGlobalBounds();

    coliAbajo.left = gp.x - gbb.width/2 + 27;
    coliAbajo.top = gp.y + gbb.height/2+2;
    coliAbajo.width = gbb.width-50;
    coliAbajo.height = 2;
    
    coliIzquierda.left = gp.x - gbb.width/2+12;
    coliIzquierda.top = gp.y - gbb.height/2 + 25 ;
    coliIzquierda.width = gbb.width/2 - 15;
    coliIzquierda.height = gbb.height -25;

    coliDerecha.left = gp.x+5;
    coliDerecha.top = gp.y - gbb.height/2 +25;
    coliDerecha.width = gbb.width/2 -20;
    coliDerecha.height = gbb.height -25;

    coliArriba.left = gp.x - gbb.width/2 + 20;
    coliArriba.top = gp.y-gbb.height/2 +25;
    coliArriba.width = gbb.width - 40;
    coliArriba.height = 5;

    cooldownSalto-=deltaTime;
    if(cooldownSalto<=0){
      auxSaltos=true;
    }

    //Moverse a la derecha si la plataforma lo permite
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
      if(!coliDerecha.intersects(plataforma.getBody().getGlobalBounds()))
        moveRight(PU_velocidad? 1.5*deltaTime : deltaTime);
      }
    //Moverse a la izquierda si la plataforma lo permite
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
      if(!coliIzquierda.intersects(plataforma.getBody().getGlobalBounds()))
        moveLeft(PU_velocidad? 1.5*deltaTime : deltaTime);
      }

//Dejar de caer si toco plataforma
 if(coliAbajo.intersects(plataforma.getBody().getGlobalBounds()) ||
   coliAbajo.intersects(suelo.getBody().getGlobalBounds()) ){
    saltos = PU_saltoDoble ? 2: 1;
    jumpSpeed = 0;
  
   } else 
      jumpSpeed+=981.0f*deltaTime;

  //caer

    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
   //  std:: cout << PU_saltoDoble << std:: endl;
      //   std:: cout << saltos << std:: endl;
        // std:: cout << "antes" << std:: endl;
      if(auxSaltos==true && saltos > 0){
            //  std:: cout << "entra" << std:: endl;
          // std:: cout << "_-------------------------------------__" << std:: endl;
        
        saltar();
        cooldownSalto=250*deltaTime;

        quitarVida();
        
        
   
        
        
      }
    }

    if(coliArriba.intersects(plataforma.getBody().getGlobalBounds())){
        jumpSpeed=25;
    }
    
    //Caída constante
    body.move(0,jumpSpeed*deltaTime);

    std::cout<< "Salto doble: " << PU_saltoDoble << "-----" << "auxSaltos: " << auxSaltos << "-----" << "Saltos: "<< saltos <<std::endl;
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
  if(saltos > 0 && auxSaltos){
        auxSaltos= false;
        jumpSpeed = -sqrtf(2.0f * 981.0f * jumpHeight);
        saltos--;
      }
}
void Player::quitarVida(){
  if(vida > 0)
  vida--;
  // aqui ira la animacion de morir
}


void Player::obtenerPU_SaltoDoble(){
  PU_saltoDoble=true;
}

void Player::setArma(int p_arma){
  arma = p_arma;
}

void Player::setAuxSaltos(){
  auxSaltos= true;
}

void Player::obtenerPU_Velocidad(){
  PU_velocidad=true;
}

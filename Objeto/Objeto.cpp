#pragma once
#include "Objeto.h"
#include <SFML/Graphics.hpp>
#include <iostream>

    
    
    
    Objeto::~Objeto(){}
    Objeto::Objeto(sf::Texture* tex,sf::Vector2f size,  sf::Vector2f Posicion, int t){

        body.setFillColor(sf::Color(0,255,0));
      
         
            body.setSize(size);
            body.setTexture(tex);
            body.setPosition(Posicion);

        tipo = std::min(std::max(t,2),1);


    }

    //t --> tipo
    void Objeto::update(Player &otherBody){

        if( sf::Keyboard::isKeyPressed(sf::Keyboard::E) && body.getGlobalBounds().intersects(otherBody.getBody().getGlobalBounds())){

            body.setSize(sf::Vector2f(0,0));
            body.setPosition(-500,-500); //lejos de la accion  
            

            switch (tipo){
            
                case 1:
                    otherBody.setArma(1);
                    break;

                case 2:
                    otherBody.obtenerPU_SaltoDoble();
                    break;
            
            default:
                std:: cout <<"Default" << std::endl;
                break;
            } 

        }

    }


    void Objeto::recogido(){

    }

    void Objeto::setTipo(int t){
        tipo = t;
    }

    int Objeto::getTipo(){
         return tipo;
    }














    void Objeto:: draw(sf::RenderWindow& window){ window.draw(body);}
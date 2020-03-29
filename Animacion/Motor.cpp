#include "Motor.h"

bool Motor::instanced = false;

bool Motor::crearVentana(){

    bool devolver = false;

    if(!instanced){

        devolver = true;

        ventana.create(sf::VideoMode(1080,720),"Totally not Pengo");

        updateClock.restart();

        instanced = true;
    }

    return(devolver);

}

bool Motor::dibujo(sf::RectangleShape entrada){

    bool devolver = false;

    if(instanced){

        ventana.draw(entrada);

        devolver = true;

    }
    
    return(devolver);
}

bool cargarSprite(sf::Texture& entrada, std::string fichero){

    bool devolver = true;

    if(!entrada.loadFromFile("resources/" + fichero)){


        devolver = false;

    }

    return(devolver);

}

void Motor::recorte(sf::RectangleShape &entrada,  int xi,int yi, int lengthX, int lengthY){

    entrada.setOrigin(xi + (lengthX/2),yi+(lengthY/2));

    entrada.setTextureRect(sf::IntRect(xi,yi,lenghtX,lengthY));

}

void Motor::setTamanyoCuerpo(sf::RectangleShape &cuerpo,sf::Vector2f entrada){

    cuerpo.setSize(entrada);

}

void setTextura(sf::RectangleShape& cuerpo, sf::Texture entrada){

    cuerpo.setTexture(texture);

}

void posicionar(sf::RectangleShape& entrada, float x, float y){

    entrada.setPosition(x,y);

}

float Motor::getReloj(){

    float devolver = updateClock.getElapsedTime().asSeconds();

    return(devolver);
}

float Motor::restartReloj(){

    float devolver = updateClock.getElapsedTime().asSeconds();

    return(devolver);

}
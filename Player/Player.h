#pragma once
#include <SFML/Graphics.hpp>
#include "../Animacion/Animacion.h"
#include "../Collider/Collider.h"
#include "../Plataforma/Plataforma.h"

class Player
{
private:
    sf::Vector2u textura;
    sf::RectangleShape body;
    int vida;
    float velocidad;
    int saltos;
    int arma;
    bool PU_saltoDoble; bool PU_velocidad; bool PU_slowhits; // Powerups, se pueden hacer un array mas adelante
    float jumpSpeed;
    float jumpHeight; //Constante (en principio)
    Animacion animacion;
    bool auxSaltos; // inicialmente true, que puede saltar dos veces
    


public:
    //CANON
    Player(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
    ~Player() ;

    //FUNCIONALIDAD
    void draw(sf::RenderWindow& window);
    void update(float deltaTime, Plataforma plataforma, Plataforma suelo);
    Collider getCollider(){return Collider(body);}
    
    void saltar();
    void quitarVida();

    //GET
    int getSaltos(){return saltos;}
    int getArma(){return arma;}
    bool getPU_SaltoDoble(){return PU_saltoDoble;}; 
    bool getPU_Velocidad(){return PU_velocidad;}; 
    bool getPU_Slowhits(){return PU_slowhits;};
    float getJumpSpeed(){return jumpSpeed;};
    sf::RectangleShape getBody(){return body;}

    //SET
    void obtenerPU_SaltoDoble();
    void obtenerPU_Velocidad();
    void obtenerPU_Slowhits();

    void perderPU_SaltoDoble();
    void perderPU_Velocidad();
    void perderPU_Slowhits();

 
    void setVelocidad();
    void setArma(int);
    void setAuxSaltos();//pone el aux de doble salto a true, que puede volver a saltar

    void moveRight(float deltaTime);
    void moveLeft(float deltaTime);

    sf::FloatRect coliAbajo;
    sf::FloatRect coliArriba;
    sf::FloatRect coliIzquierda;
    sf::FloatRect coliDerecha;
};
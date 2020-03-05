#include <SFML/Graphics.hpp>
#include "Collider.h"


Collider::~Collider(){}
Collider::Collider(sf::RectangleShape &body) :  body(body){

}

bool Collider::checkCollider(Collider &other, float push){
    // posicion y centro del objeto pasado
    sf::Vector2f otherPosicion = other.getPosicion();
    sf::Vector2f otherMitad = other.getMitadSize();
    // posicion y centro de mi objeto
    sf::Vector2f thisPosicion = getPosicion();
    sf::Vector2f thisMitad = getMitadSize();

    float dx; float dy;

    return false;
}
void Collider::Move( float dx, float dy ) { body.move(dx,dy); }
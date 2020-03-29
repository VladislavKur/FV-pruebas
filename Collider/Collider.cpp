#include <SFML/Graphics.hpp>
#include "Collider.h"


Collider::~Collider(){}
Collider::Collider(sf::RectangleShape &body) :  body(body){

}

bool Collider::checkCollision(Collider & other, float push) {
    // posicion y centro del objeto pasado
    sf::Vector2f otherPosicion = other.getPosicion();
    sf::Vector2f otherMitad = other.getMitadSize();
    // posicion y centro de mi objeto
    sf::Vector2f thisPosicion = getPosicion();
    sf::Vector2f thisMitad = getMitadSize();

    float deltaX = otherPosicion.x - thisPosicion.x; 
    float deltaY = otherPosicion.y - thisPosicion.y;
    float intersectX = abs(deltaX) - (otherMitad.x + thisMitad.x);
    float intersectY = abs(deltaY) - (otherMitad.y + thisMitad.y);

    if(intersectX < 0.0f && intersectY < 0.0f){


        push = std::min(std::max(push,1.0f),0.0f);

        if(intersectX > intersectY){
            if(deltaX > 0.0f){
                Move(intersectX *(1.0f-push),0.0f);
                other.Move(-intersectX * push, 0.0f);
            }else{
                Move(-intersectX *(1.0f-push),0.0f);
                other.Move(intersectX * push, 0.0f);
            }
        }else{
            if(deltaY > 0.0f){
                Move(0.0f,intersectY *(1.0f-push));
                other.Move(0.0f,-intersectY * push);
            }else{
                Move(0.0f,-intersectY *(1.0f-push));
                other.Move(0.0f, intersectY * push);
            }
        }

        return true;
    }

    return false;
}

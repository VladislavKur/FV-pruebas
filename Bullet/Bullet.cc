#include "Bullet.h"

Bullet::Bullet(float p_x, float p_y, bool p_facing) : body(){
    lifetime=5;

    facing=p_facing;
    
    body.setPosition(p_x, p_y);
    body.setFillColor(sf::Color(255,128,0));
    body.setRadius(10);
}

void Bullet::update(float deltaTime){
    lifetime-=deltaTime;
    body.move( (facing ? 1 : -1) * 1200*deltaTime,0);
}

void Bullet::draw(sf::RenderWindow& window){
    window.draw(body);
}
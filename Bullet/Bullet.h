#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::CircleShape body;
    bool facing;
    
public:
    Bullet(float, float, bool);
    ~Bullet() {}

    float lifetime;
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};
#pragma once
#include <SFML/Graphics.hpp>

#define maxBullets 64

class Bullet
{
private:
    sf::CircleShape body;
    bool facing;
    
public:
    Bullet(float, float, bool);
    ~Bullet() {}

    float lifetime; //Contador que destruye la bala cuando llega a 0
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    static Bullet* bullets[maxBullets];
    static void initBulletArray();
    static bool array_inicializado;
};
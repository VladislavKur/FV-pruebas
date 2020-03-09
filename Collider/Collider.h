#pragma once
#include <SFML/Graphics.hpp>

class Collider { 
    public:
        ~Collider();
        Collider(sf::RectangleShape &body);
        

        bool checkCollision(Collider &other, float push);

        void Move( float dx, float dy ) { body.move(dx,dy); }
        sf::Vector2f getPosicion(){return body.getPosition(); }
        sf::Vector2f getMitadSize() { return body.getScale() / 2.0f; }

    private:

        sf::RectangleShape &body;
       
};

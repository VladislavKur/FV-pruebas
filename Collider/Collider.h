#include <SFML/Graphics.hpp>
//#include "Player/Player.h"
class Collider{ 
    public:
        ~Collider();
        Collider(sf::RectangleShape &body);

        bool checkCollider(Collider &other, float push);
        void Move( float dx, float dy ) { body.move(dx,dy); }
        sf::Vector2f getPosicion(){return body.getPosition(); }
        sf::Vector2f getMitadSize() { return body.getSize() / 2.0f; }

    private:

        sf::RectangleShape &body;
};

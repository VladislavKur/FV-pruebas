#include <SFML/Graphics.hpp>
#include "../Collider/Collider.h"


#ifndef PLATAFORMA_H
#define PLATAFORMA_H


class Plataforma{

    public:

        ~Plataforma();
        Plataforma(sf::Texture* Textura, sf::Vector2f Size, sf::Vector2f Posicion);

        void Draw(sf::RenderWindow& window);

        Collider getCollider(){return Collider(body);}
        sf::RectangleShape getBody();

    private:

    sf::RectangleShape body;

};

#endif
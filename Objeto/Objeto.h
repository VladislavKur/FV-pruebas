#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/Player.h"


class Objeto
{

    public:
    ~Objeto();//t --> tipo
    Objeto(sf::Texture* tex,sf::Vector2f size, sf::Vector2f Posicion, int t);

    void draw(sf::RenderWindow& window);
    void update(Player otherBody);


    void recogido();
    int getTipo();
    void setTipo(int t);

    private:

    sf::RectangleShape body;

    int tipo;


};
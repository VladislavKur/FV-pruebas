#include <SFML/Graphics.hpp>

class Plataforma{

public:

Plataforma(sf::Texture &textura, sf::Vector2f posicion, sf::Vector2f tamanyo, int id);
~Plataforma();

private:

int id; // 0 no pasar 1 pasar




};
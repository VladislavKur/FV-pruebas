#pragma once
#include <SFML/Graphics.hpp>
//ALEJANDRO EL GUAPO ME HA DICHO QUE PONGA RELOJES DENTRO DE ANIMACION
class Animacion{

    public:
        Animacion(sf::Texture* textura, sf::Vector2u cantidadImagenes, float SwitchTimeSprite);
        ~Animacion();
        void Update(float deltaTime);
        void setSprite(sf::Vector2u Sprites);
        
        sf::IntRect textureRect;

    private:
        sf::Vector2u cantidadImagenes;
        sf::Vector2u spriteActual;
        

        float temporizador;
        float SwitchTimeSprite;

};
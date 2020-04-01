#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MOTOR_H
#define MOTOR_H

    class Motor{

        friend class Animacion;

        private:
            static sf::RenderWindow ventana;
            static bool instanced;
            static sf::Clock updateClock;
        protected:
            static bool dibujo(sf::RectangleShape entrada);
            static bool cargarSprite(sf::Texture& entrada, std::string fichero);//wip
            static void recorte(sf::RectangleShape &entrada, int xi, int yi, int lengthX, int lengthY);
            static void setTamanyoCuerpo(sf::RectangleShape& cuerpo,sf::Vector2f entrada);
            static void setTextura(sf::RectangleShape& cuerpo, sf::Texture entrada);
            static void posicionar(sf::RectangleShape& entrada, float x, float y);
        public:
            static bool crearVentana();
            static float getReloj();
            static int getRelojM();
            static float restartReloj();
            static int restartRelojM();
            static void close();
            static void limpieza();
            static void mostrar();
            static bool getOpen();
            static char readEventTeclado();

    };


#endif
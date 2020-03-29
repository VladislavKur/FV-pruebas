#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MOTOR_H
#define MOTOR_H

    class Motor{

        private:
            static sf::RenderWindow ventana;
            static bool instanced;
            static sf::Clock updateClock;
        protected:
            static bool dibujo(sf::RectangleShape entrada);
            static bool cargarSprite(sf::Texture& entrada, std::string fichero);//wip
            static void recorte(sf::RectangleShape &entrada, int xi, int yi, int xf, int yf);
            static void posicionar(sf::RectangleShape& entrada, float x, float y);
        public:
            static bool crearVentana();
            static float getReloj();
            static float restartReloj();
            static void close();
            static void limpieza();
            static void mostrar();
            static bool getOpen();
            static char readEventTeclado();

    };


#endif
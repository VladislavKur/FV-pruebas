#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player/Player.h"
#include "../enemigos/enemigo.h"
#include "../Bullet/Bullet.h"

#ifndef JUEGO_H
#define JUEGO_H

    class Juego{

        private:
            Player jugador;
            Enemigo* enemies = NULL;
            Bullet* bulletPlayer = NULL;
            Bullet* bulletEnemies = NULL;
            static Juego* pinstance;

        protected:
            Juego();
        public:
            static Juego *instance();
            void update(float updateTime);
            void render(float deltaTime);            

    };

#endif
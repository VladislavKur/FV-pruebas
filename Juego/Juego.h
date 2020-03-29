#pragma once
#include <SFML/Graphic.hpp>
#include <iostream>
#include "../Player/Player.h"
#include "../enemigos/enemigo.h"
#include "../Bullet/Bullet.h"

#ifndef JUEGO_H
#define JUEGO_H

    class Juego{

        private:
            Player::Player jugador;
            Enemigo::Enemigo* enemies = NULL;
            Bullet::Bullet* bulletPlayer = NULL;
            Bullet::Bullet* bulletEnemies = NULL;
            static Juego* pinstance;

        protected:
            Juego();
        public:
            Juego instance();
            void update(float updateTime);
            void render(float deltaTime);            

    }

#endif
#include "Juego.h"

Juego::pinstance = 0;

Juego::Juego(){



}

Juego Juego::instance(){

    if(pinstance = 0){

        pinstance = new Juego();

    }

    return(pinstance);
}

void Juego::update(float updateTime){ //wip

    for(int i = 0; i < (sizeof(bulletPlayer)/sizeof(*bulletPlayer));i++){

        bulletPlayer[i].update();

    }
    for(int i = 0; i < (sizeof(bulletEnemies)/sizeof(*bulletEnemies));i++){

        bulletEnemies[i].update();

    }
    Juego::jugador.update();
    for(int i = 0; i < (sizeof(enemies)/sizeof(*enemies));i++){

        Juego::enemies[i].render();

    }

}

void Juego::render(float deltaTime){ //wip

    for(int i = 0; i < (sizeof(bulletPlayer)/sizeof(*bulletPlayer));i++){

        bulletPlayer[i].render();

    }
    for(int i = 0; i < (sizeof(bulletEnemies)/sizeof(*bulletEnemies));i++){

        bulletEnemies[i].render();

    }
    Juego::jugador.render();
    for(int i = 0; i < (sizeof(enemies)/sizeof(*enemies));i++){

        Juego::enemies[i].render();

    }

}
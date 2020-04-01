#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animacion/Motor.h"
#include "Juego/Juego.h"

#define kVel 5

int main() {
  /////////////
  ////START////
  /////////////

  const float UPDATE_TICK_TIME = 15.0;

  //Creamos una ventana
  if(Motor::crearVentana()){ //si la ventana se crea correctamente

    float elapsus;
    float delta;

    Juego* instancia = Juego::instance();

    //funcion inicializar juego de juego VERY WIP SUCH WOW

    while(Motor::getOpen()){
      if(Motor::getRelojM() > UPDATE_TICK_TIME){

        delta = Motor::restartReloj();

        instancia->update(delta);

      }

      elapsus = Motor::getRelojM();
      
      if(elapsus >= UPDATE_TICK_TIME){
        instancia->render(1.0);
      }

      else{
        instancia->render(elapsus/UPDATE_TICK_TIME);
      }
    }
  }

  return 0;
}

#include "sonido.h"

sonido::sonido(String x){
   //SONIDO 
   cout << "estoy en cargar sonido " << endl;
    if(!soundBuffer.loadFromFile(x)){
      cout<<"No se puede encontrar el audio Empujarbloque.wav"<<endl;
    }
    sound.setBuffer(soundBuffer);
}

void sonido::reproducirMusica(){
    sound.play();
}

void sonido::pausarMusica(){
    sound.stop();
}

void sonido::ponerBucle(){
    sound.setLoop(true);
}



int main(){

    RenderWindow * ventana = new RenderWindow(VideoMode(640, 480), "PRUEBA MENU");    
    String ss = "resources/AudioPengo.ogg";
    sonido  s(ss);


    while (ventana->isOpen()) {
    //Bucle de obtención de eventos
      Event event;
      while (ventana->pollEvent(event)) {

        switch (event.type){
          case Event::Closed:
            ventana->close();
          break;
          
          case Event::KeyPressed:
            //Verifico si se pulsa alguna tecla de movimiento
            switch (event.key.code) {
              case Keyboard::P:
                s.reproducirMusica();
              break;
              case Keyboard::Space:
               s.pausarMusica();
              break;
               case Keyboard::B:
               s.ponerBucle();
              break;
              default:
               
              break;
              
            }
        
          default: 
          break;  
        }
      }

      ventana->clear();
      ventana->display();
  }
 

  return 0;
}
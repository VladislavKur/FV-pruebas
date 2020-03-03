#include "menu.h"

menu::menu(float width , float heigth, Font fuente){
    font = fuente;

    texto[0].setFont(font);
    texto[0].setColor(Color::Red);
    texto[0].setString("Play");
    texto[0].setPosition(Vector2f(width/2 , heigth/(num_items +1 ) *1));


    texto[1].setFont(font);
    texto[1].setColor(Color::White);
    texto[1].setString("Options");
    texto[1].setPosition(Vector2f(width/2 , heigth/(num_items +1 ) *2));


    texto[2].setFont(font);
    texto[2].setColor(Color::White);
    texto[2].setString("Exit");
    texto[2].setPosition(Vector2f(width/2 , heigth/(num_items +1 ) *3));

    selectedItem = 0;
}

menu::~menu(){

}

void menu::draw(RenderWindow * Window){ 
    for(int i = 0; i < num_items; i++){
        Window->draw(texto[i]);
    }
}

void menu::moveUp(){
    if(selectedItem - 1 >= 0 ){
        texto[selectedItem].setColor(Color::White);
        selectedItem--;
        texto[selectedItem].setColor(Color::Red);
    }
}

void menu::moveDown(){
    if(selectedItem + 1 < num_items ){
        texto[selectedItem].setColor(Color::White);
        selectedItem++;
        texto[selectedItem].setColor(Color::Red);
    }
}

int menu::getItemPressed(){
    return selectedItem;
}

int main(){
    
    Font fuente; 
    if(!fuente.loadFromFile("resources/PixelBug.otf")){
        cout<< "NO SE CARGA"<<endl;
    }

    RenderWindow * ventana = new RenderWindow(sf::VideoMode(640, 480), "PRUEBA MENU");    
    menu m = menu(ventana->getSize().x , ventana->getSize().y, fuente);
 
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
              case Keyboard::Up:
                m.moveUp();
              break;
              case Keyboard::Down:
                m.moveDown();
              break;
              case Keyboard::Return:
                switch (m.getItemPressed()){
                  case 0:
                      cout<<"eligo play" << endl;
                  break;
                  
                  case 1: 
                      cout<<"eligio opciones"<<endl;
                    break;
                  case 2:
                      cout<<"eligo salir"<<endl;
                      ventana->close();
                    break;
                }
              break;
              default:
              break;
              
            }
        
          default: 
          break;  
        }
      }

      ventana->clear();
      m.draw(ventana);
      ventana->display();
  }
 

  return 0;
}

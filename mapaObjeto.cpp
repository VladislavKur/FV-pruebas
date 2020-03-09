#include "mapaObjeto.h"

mapaObjeto::mapaObjeto(){
  
}

void mapaObjeto::dibujar(RenderWindow * ventana){
    TiXmlDocument doc;
    if(!doc.LoadFile("MapaFinal.tmx")){
        cout<< "ERROR AL CARGAR EL DOCUMENTO"<<endl;
    }else{
        cout << "LO HE CARGADO" << endl;
    }

    TiXmlElement * map = doc.FirstChildElement("map");
    TiXmlElement * objectgroup = map->FirstChildElement("objectgroup");
    TiXmlElement * object = objectgroup->FirstChildElement("object");
    _numObjects = 0;
    while(object){
        object = object->NextSiblingElement("object");
        _numObjects++;
    }
    cout<< "numObjects " << _numObjects<< endl;
    objects = new TiXmlElement * [_numObjects];
    objetos = new RectangleShape * [_numObjects];
    
    object = objectgroup->FirstChildElement("object");
    
    cout<<"object " << object->Attribute("id")<<endl;
    int num = 0; 
    while(object){
        objects[num] = object;
        object = object->NextSiblingElement("object");
        num++;
    }
    cout<< "num" << num <<endl; 
    
    for(int i=0; i < _numObjects; i++){
        //cout << "OBJETO  ID = " << objects[i]->Attribute("id") << endl;
        objects[i]->QueryIntAttribute("width", &_widthObject);
        //cout << "width " << _widthObject<<endl;
        objects[i]->QueryIntAttribute("height", &_heightObject);
        //cout << "height " << _heightObject<<endl;
        objects[i]->QueryIntAttribute("x", &_x);
        //cout << "x " << _x<<endl;
        objects[i]->QueryIntAttribute("y", &_y);
        //cout << "y " << _y << endl;
        objetos[i] = new RectangleShape(Vector2f(_widthObject, _heightObject));
        
        if(objetos[i] != nullptr ){
         cout<< "TENGOO ALGO" <<endl;
        }
        
        objetos[i]->setPosition(_x,_y);
        objetos[i]->setFillColor(Color(255, 0 , 0));
        ventana->draw(*objetos[i]);
    }
}

int main(){
  RenderWindow * window = new RenderWindow(sf::VideoMode(640, 480), "Prueba cargar mapa");
  mapaObjeto * mundo = new mapaObjeto();
  View * camara = new View(Vector2f(0.0f, 0.0f), Vector2f(480.0f , 320.0f));
  
  Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  Sprite s(tex);
  s.setPosition(Vector2f(0,760));
  s.setTextureRect(IntRect(0, 0 , 75 ,75));

  cout<<"he creado el mapa"<<endl;
  while (window->isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    while (window->pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window->close();
      break;

         case Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {

        //Mapeo del cursor
        case Keyboard::Right:
            s.move(5, 0);
        break;

        case Keyboard::Left:
            s.move(-5, 0);
          break;

        case Keyboard::Up:
            s.move(0, -5);
          break;

        case Keyboard::Down:
            s.move(0, 5);
          break;
         
        default: 
        break;
        }
      break;

      default: 
      break;
      
      }
      
    window->clear();
    mundo->dibujar(window); 
    window->draw(s);
    camara->setCenter(s.getPosition());
    window->setView(*camara);
    window->display();
    }
  }
}
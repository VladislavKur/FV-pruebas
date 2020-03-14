#include "mapa.h"

mapa::mapa(){

}

void mapa::cargarmapa(const char * f){

  if(!doc.LoadFile(f)){
    cout<< "ERROR AL CARGAR EL DOCUMENTO"<<endl;
  }else{
    cout << "LO HE CARGADO" << endl;
  }
  map = doc.FirstChildElement("map");

  map->QueryIntAttribute("width", &_width);
  map->QueryIntAttribute("height", &_height);
  map->QueryIntAttribute("tilewidth", &_tileWidth);
  map->QueryIntAttribute("tileheight", &_tileHeight);
 
  TiXmlElement * tileset = map->FirstChildElement("tileset");
  while(tileset){
     _numTilesets++;
    tileset = tileset->NextSiblingElement("tileset");
  }
  cout << endl;
  cout <<"numtileset =  " <<_numTilesets<<endl;

  imagenes = new TiXmlElement *[_numTilesets]; 
  _imgwidth = new int[_numTilesets];
  _imgheight = new int[_numTilesets];
  cambio = new int[_numTilesets];
  _tilesetTexture = new Texture[_numTilesets];
  
  tileset = map->FirstChildElement("tileset");
  int num = 0;
  while(tileset){
    cout << "entro en el primer while"<<endl;
    tileset->QueryIntAttribute("tilecount", &cambio[num]);
    cout << " cambio " << cambio[num] << "  num " << num << endl;
    imagenes[num] =  tileset->FirstChildElement("image");
    tileset = tileset->NextSiblingElement("tileset");
    num++;
  }

  for(int i = 0; i < _numTilesets; i++){
    const char *filename = imagenes[i]->Attribute("source");
    if(filename == NULL){
      cout<<" ERRRORRRRR file" << i<<endl;
    }else{
      cout<<"tengo algo file " << i << endl;
    }
    imagenes[i]->QueryIntAttribute("width", &_imgwidth[i]);
    imagenes[i]->QueryIntAttribute("height", &_imgheight[i]);

    if(!_tilesetTexture[i].loadFromFile(filename)){
      cout<<"NO SE CARGA LA TEXTURA = " << i <<endl;
    }else{
      cout<< "TENGO TEXTURA = " << i <<endl;
    }
  }

  TiXmlElement *layer = map->FirstChildElement("layer");
  if(layer == NULL){
      cout<<" ERRRORRRRR 2"<<endl;
  }else{
      cout<<"tengo algo 2" << endl;
  }
  
  while(layer){
    _numLayers++;
    layer = layer->NextSiblingElement("layer");
  }

  //reservar memoria
  _tilemap = new int **[_numLayers];
  for(int i = 0; i < _numLayers; i++){
    _tilemap[i] = new int * [_height];
  }
  for(int i = 0; i < _numLayers; i++){
    for(int j = 0; j < _height; j++){
      _tilemap[i][j] = new int [_width];
    }
  }

    //reservar memoria
  _tilemapSprite = new Sprite ***[_numLayers];
  for(int i = 0; i < _numLayers; i++){
    _tilemapSprite[i] = new Sprite ** [_height];
  }
  for(int i = 0; i < _numLayers; i++){
    for(int j = 0; j < _height; j++){
      _tilemapSprite[i][j] = new Sprite * [_width];
    }
  }

  TiXmlElement * data;
  for(int l=0; l<_numLayers; l++){
    if( l == 0 ){
        data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    }else{
        data = map->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    }
    for(int y=0; y<_height; y++){
      for(int x=0; x<_width; x++){ 
        data->QueryIntAttribute("gid", &_tilemap[l][y][x]);
        data = data->NextSiblingElement("tile");
      }
    }
  }

}

void mapa::crearSprites(){

  for(int l=0; l<_numLayers; l++){
    for(int y=0; y<_height; y++){
      for(int x=0; x<_width; x++){
      int imagen = 0;
      bool pintada = false;
        for(int k = 0; k< _numTilesets && !pintada; k++){
          int gid = _tilemap[l][y][x];
          if(imagen != 0){
            gid = gid - cambio[k-1];
          }
          if(gid <=  cambio[k]){
            if(gid>=_tileWidth*_tileHeight){
              cout << "Error, gid at (l,x,y)= (" << l << "," << x << "," 
              << y << ") :" << gid << " fuera del rango del tileset (" 
              << _width*_height << ")" << endl;
            }else if(gid > 0){
              _tilemapSprite[l][y][x] = new Sprite(_tilesetTexture[k]);
              int Tcolumnas = _imgwidth[k] / _tileWidth; 
              int fila = (gid / Tcolumnas);
              int columna = (gid % Tcolumnas);
              if(columna == 0){
                fila = fila - 1;
                columna = Tcolumnas -1 ;
              }else{
                columna = columna - 1;
              }
              if(columna < 0){
                columna = 0;
              }
              _tilemapSprite[l][y][x]->setTextureRect(IntRect(columna*32, fila*32, 32, 32));
              _tilemapSprite[l][y][x]->setPosition(x*_tileWidth, y*_tileHeight);
              pintada = true;
            }else{
              _tilemapSprite[l][y][x] = NULL;
            }
          }else{
            imagen++;
          }
        }
      }
    }
  }

}


void mapa::crearObjetos(){

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
    }
}

void mapa::render(RenderWindow * ventana){
  


  for(int l=0; l<_numLayers; l++){
    for(int y=0; y<_height; y++){
      for(int x=0; x<_width; x++){
      int imagen = 0;
      bool pintada = false;
        for(int k = 0; k< _numTilesets && !pintada; k++){
          int gid = _tilemap[l][y][x];
          if(imagen != 0){
            gid = gid - cambio[k-1];
          }
          if(gid <=  cambio[k]){
            if(gid>=_tileWidth*_tileHeight){
              cout << "Error, gid at (l,x,y)= (" << l << "," << x << "," 
              << y << ") :" << gid << " fuera del rango del tileset (" 
              << _width*_height << ")" << endl;
            }else if(gid > 0){
              ventana->draw(*_tilemapSprite[l][y][x]);
              pintada = true;
            }else{
              _tilemapSprite[l][y][x] = NULL;
            }
          }else{
            imagen++;
          }
        }
      }
    }
  }

  for(int i=0; i < _numObjects; i++){
    ventana->draw(*objetos[i]);
  }
}

int main(){
  RenderWindow * window = new RenderWindow(sf::VideoMode(640, 480), "Prueba cargar mapa");
  const char * file = "MapaFinal.tmx";
  //Bucle del juego
  mapa * mundo = new mapa();
  mundo->cargarmapa(file);
  mundo->crearObjetos();
  mundo->crearSprites();
  View * camara = new View(Vector2f(0.0f, 0.0f), Vector2f(480.0f , 320.0f));
  
  Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  Sprite s(tex);
  s.setPosition(Vector2f(0,0));
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
    mundo->render(window); 
    window->draw(s);
    camara->setCenter(s.getPosition());
    window->setView(*camara);
    window->display();
    }
  }
}

/*
void mapa::liberar(){
    //liberar memoria
    for(int i = 0; i < _numLayers; i++)
    {
        for(int j = 0; j < _height; j++)
        {
            delete[] _tilemap[i][j];
        }
        delete[] _tilemap[i];
    }
    delete[] _tilemap;
}*/
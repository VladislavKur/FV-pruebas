#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include "tinyxml.h"
#include "Player/Player.h"

using namespace sf;
using namespace std;

class mapaObjeto{

    public:

        mapaObjeto();
        void dibujar(RenderWindow * ventana);
    private:
 
        int _widthObject;
        int _heightObject;
        int _x;
        int _y;
        int _numObjects = 0;
        RectangleShape ** objetos;
        TiXmlElement ** objects;

};  
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include "tinyxml.h"

using namespace sf;
using namespace std;

class mapa{

    public:

        mapa(); 
        void dibujar(RenderWindow * ventana);


    private:

        VertexArray m_vertices;
        Texture m_tileset;
        int _activeLayer;
        int _width;
        int _height;
        int *_imgwidth;
        int *_imgheight;
        int * cambio;
        int _tileWidth;
        int _tileHeight;
        int _numLayers = 0;
        int _numTilesets = 0;
        int ***_tilemap;
        Sprite ****_tilemapSprite;
        Texture *_tilesetTexture;
        Sprite **_tilesetSprite;
        TiXmlElement ** imagenes;
};
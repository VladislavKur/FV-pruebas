#include<SFML/Graphics.hpp>
#include<iostream>

using namespace  sf;
using namespace std;

#define num_items 3
class menu{
    public: 
        menu(float width , float height, Font fuente);
        ~menu();
        void draw(RenderWindow * Window);
        void moveUp();
        void moveDown();
        int getItemPressed();

    private: 
        int selectedItem; 
        Font font; 
        Text texto[num_items];
};
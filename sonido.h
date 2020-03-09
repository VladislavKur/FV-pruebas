#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>



using namespace sf; 
using namespace std; 

class sonido{
    public: 
        sonido(String x);
        void reproducirMusica();
        void pausarMusica();
        void ponerBucle();
    private:
        SoundBuffer soundBuffer;
        Sound sound;
};
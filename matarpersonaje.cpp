#include <SFML/Graphics.hpp>
#include <iostream>



#define kVel 5

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(1200, 1200), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  /////////////
  ///Enemigo///
  /////////////

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite enemigo(tex);

  //Le pongo el centroide donde corresponde
  enemigo.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  enemigo.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  enemigo.setPosition(100, 100);

  /////////////
  //Personaje//
  /////////////
  sf::Sprite personaje(tex);

  personaje.setOrigin(75 / 2, 75 / 2);
  personaje.setTextureRect(sf::IntRect(1 * 75, 1 * 75, 75, 75));

  personaje.setPosition(500, 100);

  int vidas = 2;
  bool muerto = false;
  //Bucle del juego
  while (window.isOpen()) {
    
    if(personaje.getGlobalBounds().intersects(enemigo.getGlobalBounds()) && vidas > 0){
      vidas--;
      muerto = true;
    }
    if(vidas==0){
        std::cout << "Muerto" << std::endl;
        
    }
    
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {
      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {
                  //Mapeo del cursor
            case sf::Keyboard::Right:
                personaje.setTextureRect(sf::IntRect(97, 0, 15, 15));
                personaje.setScale(3,3);
            //Escala por defecto
            personaje.setScale(1, 1);
            personaje.move(kVel, 0);
            break;

            case sf::Keyboard::Left:
            personaje.setTextureRect(sf::IntRect(1 * 75, 1 * 75, 75, 75));
            //Reflejo vertical
            personaje.setScale(-1, 1);
            personaje.move(-kVel, 0);
            break;

            case sf::Keyboard::Up:
            personaje.setTextureRect(sf::IntRect(1 * 75, 1 * 75, 75, 75));
            personaje.move(0, -kVel);
            break;

            case sf::Keyboard::Down:
            personaje.setTextureRect(sf::IntRect(1 * 75, 1 * 75, 75, 75));
            personaje.move(0, kVel);
            break;

            //Tecla ESC para salir
            case sf::Keyboard::Escape:
            window.close();
            break;

            //Cualquier tecla desconocida se imprime por pantalla su código
            default:
            std::cout << event.key.code << std::endl;
            break;
        }
      }
    }

    window.clear();
    if(!muerto)
      window.draw(personaje);
    else{
      personaje.setScale(personaje.getScale().x * 0.9, personaje.getScale().y * 0.9);
      window.draw(personaje);
    }
    window.draw(enemigo);
    window.display();
  }

  return 0;
}
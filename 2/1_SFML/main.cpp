// g++ -c main.cpp -ID:/Programs/SFML/SFML-2.6.1/include -DSFML_STATIC
// g++ main.o -o main -LD:/Programs/SFML/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s
// -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
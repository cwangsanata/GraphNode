#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
  sf::CircleShape shape(25.f);
  shape.setFillColor(sf::Color(255, 255, 0));
  shape.setPosition(100, 100);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
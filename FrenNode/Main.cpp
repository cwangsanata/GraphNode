#include <SFML/Graphics.hpp>
#include <iostream>
#include "FriendNode.h"

int main()
{
  // Window settings
  sf::ContextSettings settings;
  settings.antialiasingLevel = 10;
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Default, settings);
  
  // TEST
  sf::CircleShape shape(25.f);
  shape.setFillColor(sf::Color(255, 255, 0));
  shape.setPosition(100, 100);
  shape.setOrigin(25, 25);

  sf::CircleShape shapeTwo(25.f);
  shapeTwo.setFillColor(sf::Color(255, 255, 0));
  shapeTwo.setPosition(200, 200);
  shapeTwo.setOrigin(25, 25);

  FriendNode friendOne;

  sf::Vertex line[] = 
  {
    // Testing line in viewer
    sf::Vertex(sf::Vector2f(100, 100)),
    sf::Vertex(sf::Vector2f(200, 200))
  };

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
    window.draw(shapeTwo);
    window.draw(friendOne.getCircle());
    window.draw(line, 2, sf::Lines);
    window.display();
  }

  return 0;
}
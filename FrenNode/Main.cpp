#include <SFML/Graphics.hpp>
#include <iostream>
#include "FriendNode.h"
#include "Link.h"

#define WIDTH 1000
#define HEIGHT 1000

int main()
{
  // Window settings
  sf::ContextSettings settings;
  settings.antialiasingLevel = 100;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "FrenNode", sf::Style::Default, settings);
  
  // TEST
  FriendNode friendOne; // (500, 500)
  FriendNode friendTwo(50, 0);
  FriendNode friendThree(50, 900);
  FriendNode friendFour(100, 100);
 
  Link testLinkOne(friendTwo, friendThree);
  Link testLinkTwo(friendTwo, friendOne);
  Link testLinkThree(friendOne, friendThree);
  Link testLinkFour(friendOne, friendFour);
  Link testLinkFive(friendTwo, friendFour);


  // Window draw
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color(255, 255, 255));
    
    window.draw(testLinkOne.getLine());
    window.draw(testLinkTwo.getLine());
    window.draw(testLinkThree.getLine());
    window.draw(testLinkFour.getLine());
    window.draw(testLinkFive.getLine());

    window.draw(friendOne.getCircle());
    window.draw(friendTwo.getCircle());
    window.draw(friendThree.getCircle());
    window.draw(friendFour.getCircle());


    // Text is not working
    window.draw(friendOne.getText());

    window.display();
  }

  // TODO: Fix fullscreen more
  // include some kind of checker for the amount of people

  return EXIT_SUCCESS;
}
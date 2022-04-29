#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Link.h"

#define WIDTH 1000
#define HEIGHT 1000

// TODO: Move all getters and setters to cpp files

int main()
{
  // Window settings
  sf::ContextSettings settings;
  settings.antialiasingLevel = 100;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "FrenNode", sf::Style::Default, settings);
  window.setVerticalSyncEnabled(true);

  sf::Font font;
 /* if (!font.loadFromFile("/Resources/OpenSans-Regular.ttf"))
  {
    std::cout << "Error loading font" << std::endl;
    system("pause");
  }*/
  
  // TEST
  Node friendOne; // (500, 500)
  Node friendTwo(50, 0);
  Node friendThree(50, 900);
  Node friendFour(100, 100);
 
  Link testLinkOne(friendTwo, friendThree);
  Link testLinkTwo(friendTwo, friendOne);
  Link testLinkThree(friendOne, friendThree);
  Link testLinkFour(friendOne, friendFour);
  Link testLinkFive(friendTwo, friendFour);

  // Randomly adding friends to network
  std::vector<Node> friends;
  for (int i = 0; i < 5; i++)
  {
    int randX = std::rand() % WIDTH;
    int randY = std::rand() % HEIGHT;
    Node tempFriend(randX, randY);
    friends.push_back(tempFriend);
  }

  // Adding links to adjacent nodes in friends
  std::vector<Link> links;
  for (int i = 0; i < friends.size() - 1; i++)
  {
    Link tempLink(friends[i], friends[i+1]);
    friends[i].getFriend().addFriend(friends[i+1].getFriend());
    links.push_back(tempLink);
  }

  friends[0].getFriend().printFriends();

  // Window draw
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      else if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Escape)
        {
          window.close();
        }
      }
    }

    window.clear(sf::Color::White);
    
    window.draw(testLinkOne.getLine());
    window.draw(testLinkTwo.getLine());
    window.draw(testLinkThree.getLine());
    window.draw(testLinkFour.getLine());
    window.draw(testLinkFive.getLine());

    window.draw(friendOne.getCircle());
    window.draw(friendTwo.getCircle());
    window.draw(friendThree.getCircle());
    window.draw(friendFour.getCircle());
    
    friendOne.update();
    friendTwo.update();
    friendThree.update();
    friendFour.update();
    testLinkTwo.update();
    testLinkThree.update();
    testLinkFour.update();
    testLinkFive.update();
    testLinkOne.update();
    
    //friendOne.netForce(friendTwo);
    //friendOne.netForce(friendThree);
    friendTwo.netForce(friendOne);
    friendTwo.netForce(friendThree);
    friendTwo.netForce(friendFour);
    friendThree.netForce(friendOne);
    friendThree.netForce(friendTwo);
    friendThree.netForce(friendFour);
    friendFour.netForce(friendOne);
    friendFour.netForce(friendTwo);
    friendFour.netForce(friendThree);

    window.draw(friendOne.getTextName());
    // Draw all the links
    for (Link b : links)
    {
      window.draw(b.getLine());
      b.update();
    }


    // Draw all the nodes
    for (Node a : friends)
    {
      window.draw(a.getCircle());
      for (Node b : friends)
        a.netForce(b);

      a.update();
    }

    window.display();
  }

  // TODO: Fix fullscreen more
  // include some kind of checker for the amount of people

  return EXIT_SUCCESS;
}
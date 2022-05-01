#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "Graph.h"
#include "Node.h"
#include "Link.h"

#define WIDTH 1000
#define HEIGHT 1000

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 10;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Node", sf::Style::Default, settings);
  window.setVerticalSyncEnabled(true);

  sf::Font font;

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  { 
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  sf::Text text;
  text.setFont(font);
  text.setFillColor(sf::Color::Red);
  text.setString("Batman");
  text.setCharacterSize(10);

  // TEST
  Node friendOne; // (500, 500)
  Node friendTwo(50, 0);
  Node friendThree(50, 900);
  Node friendFour(100, 100);
  Node friendFive(750, 600);

  Link testLinkOne(friendTwo, friendThree);
  Link testLinkTwo(friendTwo, friendOne);
  Link testLinkThree(friendOne, friendThree);
  Link testLinkFour(friendOne, friendFour);
  Link testLinkFive(friendTwo, friendFour);

  std::vector<Link> links;
  links.push_back(testLinkOne);

  Graph nodeGraph;
  nodeGraph.addNode(friendOne);
  nodeGraph.addNode(friendTwo);
  nodeGraph.addNode(friendThree);
  nodeGraph.addNode(friendFour);
  nodeGraph.addNode(friendFive);

  friendOne.addAdjacent(friendTwo);
  friendOne.addAdjacent(friendThree);
  friendTwo.addAdjacent(friendThree);

  //nodeGraph.connectNodes(testLinkOne);
  //nodeGraph.connectNodes(testLinkTwo);
  //nodeGraph.connectNodes(testLinkThree);
  
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      else if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
          window.close();

      if (event.type == sf::Event::MouseButtonPressed)
      {
        float mouseX = event.mouseButton.x;
        float mouseY = event.mouseButton.y;
        Node tempNode(font, mouseX, mouseY);

        if (event.mouseButton.button == sf::Mouse::Left)
          nodeGraph.addNode(tempNode);
      }
    }

    window.clear(sf::Color::White);

    for (int i = 0; i < nodeGraph.getEdges().size(); i++)
    {
      window.draw(nodeGraph.getEdges()[i].getLine());
      nodeGraph.getEdges()[i].update();
    }
    
    for (int i = 0; i < nodeGraph.getNodes().size(); i++)
    {
      window.draw(nodeGraph.getNodes()[i].getCircle());
      window.draw(nodeGraph.getNodes()[i].getTextID());
      nodeGraph.getNodes()[i].update();
    }

    nodeGraph.connectNodes();
    window.display();
  }

  return EXIT_SUCCESS;
}
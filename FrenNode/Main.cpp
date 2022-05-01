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

  // DEMO
  Graph nodeGraph;

  Node friendOne; // (500, 500)
  Node friendTwo(50, 0);
  Node friendThree(50, 900);
  Node friendFour(300, 900);
  Node friendFive(750, 600);
  Node friendSix(900, 200);

  Link testLinkOne(friendTwo, friendThree, 10);
  Link testLinkTwo(friendTwo, friendOne, 2);
  Link testLinkThree(friendOne, friendThree);
  Link testLinkFour(friendOne, friendFour, 7);
  Link testLinkFive(friendTwo, friendFour);
  Link testLinkSix(friendFive, friendSix, 8);
  Link testLinkSeven(friendOne, friendFive, -1);

  nodeGraph.addNode(friendOne);
  nodeGraph.addNode(friendTwo);
  nodeGraph.addNode(friendThree);
  nodeGraph.addNode(friendFour);
  nodeGraph.addNode(friendFive);
  nodeGraph.addNode(friendSix);

  nodeGraph.connectNodes(testLinkOne);
  nodeGraph.connectNodes(testLinkTwo);
  nodeGraph.connectNodes(testLinkThree);
  nodeGraph.connectNodes(testLinkFour);
  nodeGraph.connectNodes(testLinkFive);
  nodeGraph.connectNodes(testLinkSix);
  nodeGraph.connectNodes(testLinkSeven);
  
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
        else if (event.key.code == sf::Keyboard::Space)
        {
          
        }
          

      float startX;
      float startY;

      if (event.type == sf::Event::MouseButtonPressed)
      {
        float mouseX = event.mouseButton.x;
        float mouseY = event.mouseButton.y;

        if (event.mouseButton.button == sf::Mouse::Left)
        {
          Node tempNode(font, mouseX, mouseY);
          nodeGraph.addNode(tempNode);
        }
      }

      if (event.type == sf::Event::MouseButtonPressed)
      {

      }
    }

    window.clear(sf::Color::White);

    for (int i = 0; i < nodeGraph.getEdges().size(); i++)
    {
      window.draw(nodeGraph.getEdges()[i].getLine());
      window.draw(nodeGraph.getEdges()[i].getTextWeight());
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
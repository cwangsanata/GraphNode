#pragma once

#include <math.h>
#include "Node.h"
// #include <iostream>

#define PI 3.14159265

/*
* Connects the two nodes together
*/

class Link
{
private:
  float angle; // In degrees
  float dx, dy;
  Node *source; 
  Node *end;
  sf::RectangleShape edge;
  int weight;
  sf::Text textWeight;
  sf::Font font;
  
public:
  Link(Node&, Node&);
  Link(Node&, Node&, int);
  Link(sf::Font, Node&, Node&, int);
  Link(sf::Font, float, float, float, float, int);

  sf::RectangleShape getLine() { return edge; }
  sf::Text getTextWeight() { return textWeight; }
  void update();
  float getAngle(float, float, float, float);
};

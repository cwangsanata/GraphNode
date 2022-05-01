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

public:
  Link(Node&, Node&);
  Link(Node&, Node&, int);
  // ~Link();
  sf::RectangleShape getLine() { return edge; }
  void update();
  float getAngle(float, float, float, float);
};

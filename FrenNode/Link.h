#pragma once

#include <math.h>
#include "FriendNode.h"
#include <iostream>

#define PI 3.14159265

/*
* Connects the two nodes together
*/

class Link
{
private:
  int red, green, blue;
  float angle; // In degrees
  float dx, dy;
  FriendNode *source; 
  FriendNode *end;
  sf::RectangleShape edge;

public:
  Link(FriendNode &, FriendNode &);

  sf::RectangleShape getLine() { return edge; }
  void update();
};

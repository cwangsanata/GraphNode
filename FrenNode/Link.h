#pragma once

#include <math.h>
#include "FriendNode.h"

#define PI 3.14159265

/*
* Connects the two nodes together
*/

class Link
{
private:
  int red, green, blue;
  FriendNode source;
  FriendNode end;
  sf::RectangleShape edge;

public:
  Link(FriendNode, FriendNode);
  sf::RectangleShape getLine()
  {
    return edge;
  }
};

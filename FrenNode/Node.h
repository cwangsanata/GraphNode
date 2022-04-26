#pragma once
/*
* Visual representation of the friends in space.
*/

#include <string>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Friend.h"

class Node
{
private:
  float radius;
  int red, green, blue;
  int x, y;
  float xVelocity, yVelocity;
  float xAccel, yAccel;
  sf::Text text;
  sf::CircleShape circle;
  Friend friendInfo;

public:
  // Constructors
  Node();
  Node(int, int);
  Node(int, int, std::string);
  // ~FriendNode();

  sf::CircleShape getCircle() { return circle; }
  int getX() { return x; }
  int getY() { return y; }
  void setX(int x_) { x = x_; }
  void setY(int y_) { y = y_; }
  int getRadius() { return radius; }
  Friend getFriend() { return friendInfo; }
  sf::Text getText() { return text; }

  bool validLoc(Node);
  void addNode(Node);
  void update();

  float getDistance(Node);
  float repulsiveForce(Node); // Universally applies
  float attractiveForce(Node); // Applies stronger to only nodes with edges
  void netForce(); // merge both forces together
  
  
};

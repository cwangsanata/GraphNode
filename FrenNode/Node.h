#pragma once
/*
* Visual representation of the friends in space.
*/

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

#include "Friend.h"

static int totalNodes; // NSFW
static int t; // Damping

class Node
{
private:
  float radius;
  int x, y;
  float xVelocity, yVelocity;
  float xAccel, yAccel;
  float k; // Constant for calculating force
  sf::Text textName;
  sf::CircleShape circle;
  Friend friendInfo;

public:
  Node();
  Node(int, int);
  Node(int, int, std::string);
  // ~FriendNode();

  sf::CircleShape getCircle() { return circle; }
  int getX() { return x; }
  int getY() { return y; }
  int getRadius() { return radius; }
  float getDistance(Node);
  Friend getFriend() { return friendInfo; }
  sf::Text getTextName() { return textName; }

  const void setXAccel(float);
  const void setYAccel(float);

  void validLoc();
  // void addNode(Node);
  void update();

  float repulsiveForce(const Node&); // Universally applies
  float attractiveForce(const Node&); // Applies stronger to only nodes with edges
  void netForce(const Node&); // merge both forces together
  float getAngle(Node);
};

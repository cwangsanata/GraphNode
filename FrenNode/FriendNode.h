#pragma once
/*
* Visual representation of the friends in space.
*/

#include <string>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Friend.h"

class FriendNode
{
private:
  float radius;
  int red, green, blue;
  int x, y;
  float xVelocity, yVelocity;
  float xAcceleration, yAcceleration;
  sf::CircleShape circle;
  sf::Text text;
  Friend friendDetails;

public:
  // Constructors
  FriendNode();
  FriendNode(int, int);
  FriendNode(int, int, std::string);
  // ~FriendNode();

  sf::CircleShape getCircle() { return circle; }
  int getX() { return x; }
  int getY() { return y; }
  void setX(int x_) { x = x_; }
  void setY(int y_) { y = y_; }
  int getRadius() { return radius; }
  sf::Text getText() { return text;}
  Friend getFriend() { return friendDetails; }

  bool validLoc(FriendNode);
  void addNode(FriendNode);
  float getDistance(FriendNode);

  void repulsiveForce(FriendNode); // Universally applies
  void attractiveForce(FriendNode); // Applies stronger to only nodes with edges
  void netForce(FriendNode); // merge both forces together
  void update();
// checkDist()
// removeFriend()
//    removes link from friend
// distanceFromFriend()
//    degrees of friendship
  
};

#pragma once
/*
* Visual representation of the friends in space.
*/

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class FriendNode
{
private:
  float radius;
  int red, green, blue;
  int x, y;
  sf::CircleShape circle;
  sf::Text text;
  std::vector<FriendNode> adjList; // Adjacency list implementation of graph

public:
  // Constructors
  FriendNode();
  FriendNode(int, int);
  ~FriendNode()
  {
  }

  sf::CircleShape getCircle() { return circle; }

  int getX() { return x; }

  int getY() { return y; }

  int getRadius() { return radius; }

  sf::Text getText() { return text;}

  bool validLoc(FriendNode);
  void addFriend(FriendNode);
  void printFriends();

// checkDist()
// removeFriend()
//    removes link from friend
// distanceFromFriend()
//    degrees of friendship
// readjust()
};

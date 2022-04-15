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
  sf::CircleShape circle;
  int x, y;
  std::vector<FriendNode> adjList; // Adjacency list implementation of graph

public:
  // Constructors
  FriendNode();
  FriendNode(int, int);
  ~FriendNode()
  {
  }

  sf::CircleShape getCircle()
  {
    return circle;
  }

  bool checkCollision(FriendNode);
  void addFriend(FriendNode);
// checkDist()
// removeFriend()
//    removes link from friend
// distanceFromFriend()
//    degrees of friendship
// readjust()

};

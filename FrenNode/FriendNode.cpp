#include "FriendNode.h"

FriendNode::FriendNode()
{
  radius = 25.0;
  x = 0; y = 0;
  red = 255; green = 255; blue = 0;
  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOrigin(-radius, -radius);
}

FriendNode::FriendNode(int x_, int y_)
{
  radius = 25.0;
  x = x_; y = y_;
  red = 255; green = 255; blue = 0;
  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOrigin(radius, radius); // need to check the math but too lazy lol lmao
}

bool FriendNode::checkCollision(FriendNode a)
{
  // TODO: Write the rest fool (maybe look at some js tutorials)
  return false;  // for each known, if the known is within a radius, readjust()
}

void FriendNode::addFriend(FriendNode a)
{
  adjList.push_back(a);
  return;
} 

  // checkDist()
  // removeFriend()
  //    removes link from friend
  // distanceFromFriend()
  //    degrees of friendship
  // readjust()



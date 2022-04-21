#include "FriendNode.h"

#define WIDTH 1000
#define HEIGHT 1000

FriendNode::FriendNode()
{
  radius = 25.0;
  x = WIDTH / 2; y = HEIGHT / 2;
  red = 255; green = 255; blue = 255;
  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));

  circle.setPosition(x, y);
  circle.setOrigin(0, 0);

  text.setString("1");
  text.setPosition(x, y);
  text.setFillColor(sf::Color(0, 0, 0));
}

FriendNode::FriendNode(int x_, int y_)
{
  radius = 25.0;
  x = x_; y = y_;
  red = 255; green = 0; blue = 0;

  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));

  circle.setPosition(x, y);
  circle.setOrigin(0, 0);
}

bool FriendNode::validLoc(FriendNode a)
{
  if (abs(x - a.getX() < 25) || abs(x - a.getX() > 25))
    return false;

  return true;
}

void FriendNode::addFriend(FriendNode a)
{
  adjList.push_back(a);
  return;
} 

void printFriends()
{

}


  // checkDist()
  // removeFriend()
  //    removes link from friend
  // distanceFromFriend()
  //    degrees of friendship
  // readjust()



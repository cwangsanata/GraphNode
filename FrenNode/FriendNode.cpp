#include "FriendNode.h"

#define WIDTH 1000
#define HEIGHT 1000

FriendNode::FriendNode()
{
  radius = .01 * WIDTH;
  x = WIDTH / 2; y = HEIGHT / 2;
  red = 255; green = 255; blue = 255;

  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));

  circle.setPosition(x, y);
  circle.setOrigin(0, 0);

  text.setString("null");
  text.setPosition(x, y);
  text.setFillColor(sf::Color(0, 0, 0));

  xVelocity = 0;
  yVelocity = 0;
  xAcceleration = 0;
  yAcceleration = 0;
}

FriendNode::FriendNode(int x_, int y_)
{
  radius = .01 * WIDTH;
  x = x_; y = y_;
  red = 255; green = 0; blue = 0;

  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));

  circle.setPosition(x, y);
  circle.setOrigin(0, 0);

  text.setString("null");
  text.setPosition(x, y);
  text.setFillColor(sf::Color(0, 0, 0));

  xVelocity = 0;
  yVelocity = 0;
  xAcceleration = 0;
  yAcceleration = 0;
}

FriendNode::FriendNode(int x_, int y_, std::string name_)
{
  radius = .01 * WIDTH;
  x = x_; y = y_;
  red = 255; green = 0; blue = 0;

  circle.setRadius(radius);
  circle.setFillColor(sf::Color(red, green, blue));
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));

  circle.setPosition(x, y);
  circle.setOrigin(0, 0);

  friendDetails.setName(name_);
  text.setString(friendDetails.getName());
  text.setPosition(x, y);
  text.setFillColor(sf::Color(0, 0, 0));

  xVelocity = 0;
  yVelocity = 0;
  xAcceleration = 0;
  yAcceleration = 0;
}

//WIP
bool FriendNode::validLoc(FriendNode a)
{
  if (abs(x - a.getX() < 2 * radius) || abs(x - a.getX() > 2 * radius))
    return false;

  if (radius)

  return true;
}

//WIP
void FriendNode::addNode(FriendNode a)
{
  if (!validLoc(a))
    return;
}

float FriendNode::getDistance(FriendNode a)
{
  float dx = a.getX() - x;
  float dy = a.getY() - y;
  return sqrt(dx*dx + dy*dy);
}

void FriendNode::update()
{
  x += xVelocity;
  y += yVelocity;
  circle.move(xVelocity, yVelocity);
}




#include "Node.h"

#define WIDTH 1000
#define HEIGHT 1000

Node::Node()
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

  text.setFillColor(sf::Color::Red);
  text.setString(friendInfo.getName());

  xVelocity = 1;
  yVelocity = 0;
  xAccel = 0;
  xAccel = 0;
}

Node::Node(int x_, int y_)
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

  text.setFillColor(sf::Color::Red);
  text.setString(friendInfo.getName());

  xVelocity = 1;
  yVelocity = 1;
  xAccel = 0;
  yAccel = 0;
}

//WIP
bool Node::validLoc(Node a)
{
  if (abs(x - a.getX() < 2 * radius) || abs(x - a.getX() > 2 * radius))
    return false;

  if (radius)

  return true;
}

//WIP
void Node::addNode(Node a)
{
  if (!validLoc(a))
    return;
}

void Node::update()
{
  x += xVelocity;
  y += yVelocity;
  circle.setPosition(x, y);
}

float Node::getDistance(Node a)
{
  float dx = a.getX() - x;
  float dy = a.getY() - y;
  return hypot(dx, dy);
}

float Node::repulsiveForce(Node a)
{
  float dist = getDistance(a);
  float netRepel = -1 / (dist * dist);
  // get angle
  // get xAccel
  // get yAccel
  // make some constant value (tinker)
  // TODO: Finish net forces

  return 0;
}

float Node::attractiveForce(Node a)
{
  // Add if (friend), attractive force is stronger
  return 0;
}

void Node::netForce()
{
  // gets accelerations and calculates a net acceleration for the node
}




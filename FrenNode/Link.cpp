#include "Link.h"

Link::Link(Node &source_, Node &end_)
{
  source = &source_;
  end = &end_;

  edge.setFillColor(sf::Color::Black);
  edge.setOrigin(0, 0);
  edge.setPosition((*source).getX() + (*source).getRadius(), (*source).getY() + (*source).getRadius());

  dx = (*end).getX() - (*source).getX();
  dy = (*end).getY() - (*source).getY();

  angle = getAngle((*source).getX(), (*source).getY(), (*end).getX(), (*end).getY());

  edge.setSize(sf::Vector2f(hypot(dy, dx), 2));
  edge.setRotation(angle);
}

void Link::update() 
{
  dx = (*end).getX() - (*source).getX();
  dy = (*end).getY() - (*source).getY();

  angle = getAngle((*source).getX(), (*source).getY(), (*end).getX(), (*end).getY());

  edge.setPosition((*source).getX() + (*source).getRadius(), (*source).getY() + (*source).getRadius());
  edge.setSize(sf::Vector2f(hypot(dy, dx), 2));
  edge.setRotation(angle);
  }

float Link::getAngle(float x1, float y1, float x2, float y2)
{
  float tempDX = x2 - x1;
  float tempDY = y2 - y1;
  float tempAngle = 0;

  if (tempDX < 0)
    tempAngle = 180 + atan(tempDY / tempDX) * (180 / PI);
  else if (tempDX > 0)
    tempAngle = atan(tempDY / tempDX) * (180 / PI);
  else if (tempDX == 0 && tempDY > 0)
    tempAngle = 90;
  else if (tempDX == 0 && tempDY < 0)
    tempAngle = -90;

  return tempAngle;
}
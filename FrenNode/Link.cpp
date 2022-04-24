#include "Link.h"

Link::Link(FriendNode source, FriendNode end)
{
  red = 0; green = 0; blue = 0;
  startX = source.getX() + source.getRadius();
  startY = source.getY() + source.getRadius();

  edge.setFillColor(sf::Color(red, green, blue));
  edge.setOrigin(0, 0);
  edge.setPosition(startX, startY);

  float dx = end.getX() - source.getX();
  float dy = end.getY() - source.getY();
  angle = 0; // In degrees

    // Initialization and rotation 
  if (dx < 0)
    angle = 180 + atan(dy / dx) * (180 / PI);
  else if (dx > 0)
    angle = atan(dy / dx) * (180 / PI);
  else if (dx == 0 && dy > 0)
    angle = 90;
  else if (dx == 0 && dy < 0)
    angle = -90;

  edge.setSize(sf::Vector2f(hypot(dy, dx), 2));
  edge.setRotation(angle);
}

void Link::update() 
{

}
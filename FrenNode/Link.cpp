#include "Link.h"

Link::Link(FriendNode source, FriendNode end)
{
  red = 0; green = 0; blue = 0;
  edge.setFillColor(sf::Color(red, green, blue));
  edge.setOrigin(0, 0);
  edge.setPosition(source.getX() + source.getRadius(), source.getY() + source.getRadius());

  float deltaX = end.getX() - source.getX();
  float deltaY = end.getY() - source.getY();
  float angle = 0;

  // JANK AF
  if (deltaX < 0)
    angle = 180 + atan(deltaY / deltaX) * (180 / PI);
  else if (deltaX > 0)
    angle = atan(deltaY / deltaX) * (180 / PI);

  if (deltaX == 0 && deltaY > 0)
    angle = 90;
  else if (deltaX == 0 && deltaY < 0)
    angle = -90;

  edge.setSize(sf::Vector2f(sqrt(deltaX*deltaX + deltaY*deltaY), 2));
  edge.setRotation(angle);

  
}
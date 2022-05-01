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

  weight = 1;

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textWeight.setFont(font);
  textWeight.setFillColor(sf::Color::Black);
  textWeight.setString(std::to_string(weight));
  textWeight.setCharacterSize(20);
  textWeight.setPosition((*source).getX() + dx / 2, (*source).getY() + dy / 2);
}

Link::Link(Node& source_, Node& end_, int weight_)
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

  weight = weight_;

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textWeight.setFont(font);
  textWeight.setFillColor(sf::Color::Black);
  textWeight.setString(std::to_string(weight));
  textWeight.setCharacterSize(20);
  textWeight.setPosition((*source).getX() + dx / 2, (*source).getY()+ dy / 2);
}

Link::Link(sf::Font font_, float x_1, float y_1, float x_2, float y_2, int weight_ = 1)
{
  
  edge.setFillColor(sf::Color::Black);
  edge.setOrigin(0, 0);
  edge.setPosition(x_1, y_1);

  dx = x_2 - x_1;
  dy = y_2 - y_1;

  angle = getAngle(x_1, y_1, x_2, y_2);

  edge.setSize(sf::Vector2f(hypot(dy, dx), 2));
  edge.setRotation(angle);

  weight = weight_;

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textWeight.setFont(font);
  textWeight.setFillColor(sf::Color::Black);
  textWeight.setString(std::to_string(weight));
  textWeight.setCharacterSize(20);
  textWeight.setPosition((*source).getX() + dx / 2, (*source).getY() + dy / 2);
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
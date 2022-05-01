#include "Node.h"

#define WIDTH 1000
#define HEIGHT 1000
#define PI 3.14159265

Node::Node()
{
  radius = .03 * std::sqrt(WIDTH * HEIGHT);
  x = WIDTH / 2; y = HEIGHT / 2;
  id = "0";

  circle.setRadius(radius);
  circle.setFillColor(sf::Color::Red);
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color::Black);
  circle.setPosition(x, y);

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textID.setFont(font);
  textID.setFillColor(sf::Color::Black);
  textID.setString(id);
  textID.setCharacterSize(20);
  textID.setPosition(x + radius, y + radius);

  xVelocity = 0;
  yVelocity = 0;
  xAccel = 0;
  xAccel = 0;

  
  k = std::sqrt(WIDTH * HEIGHT) / ++totalNodes;
}

Node::Node(float x_, float y_)
{
  radius = .03 * std::sqrt(WIDTH * HEIGHT);
  x = x_; y = y_;
  id = std::to_string(totalNodes);

  circle.setRadius(radius);
  circle.setFillColor(sf::Color::White);
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));
  circle.setPosition(x, y);

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textID.setFont(font);
  textID.setFillColor(sf::Color::Black);
  textID.setString(id);
  textID.setCharacterSize(20);
  textID.setPosition(x + radius, y + radius);

  xVelocity = 0;
  yVelocity = 0;
  xAccel = 0;
  yAccel = 0;

  k = std::sqrt(WIDTH * HEIGHT) / ++totalNodes;
}

Node::Node(const sf::Font& font_, float x_ = 500, float y_ = 500)
{
  radius = .03 * std::sqrt(WIDTH * HEIGHT);
  x = x_; y = y_;
  id = std::to_string(totalNodes);

  circle.setRadius(radius);
  circle.setFillColor(sf::Color::White);
  circle.setOutlineThickness(2.0);
  circle.setOutlineColor(sf::Color(0, 0, 0));
  circle.setPosition(x, y);

  if (!font.loadFromFile("Montserrat-Regular.ttf"))
  {
    std::cout << "ERROR: CANNOT LOAD FONT" << std::endl;
    system("pause");
  }

  textID.setFont(font_);
  textID.setFillColor(sf::Color::Black);
  textID.setString(id);
  textID.setCharacterSize(20);
  textID.setPosition(x + radius, y + radius);

  xVelocity = 0;
  yVelocity = 0;
  xAccel = 0;
  yAccel = 0;

  k = std::sqrt(WIDTH * HEIGHT) / ++totalNodes;

}

Node::~Node()
{
}

void Node::addAdjacent(Node &a)
{
  adjList.push_back(a);
}

// TODO: Should be boundary check repulsion
void Node::validLoc()
{
  if (x > WIDTH)
    xVelocity -= 1;
  else if (x < 0)
    xVelocity += 1;
  if (y > HEIGHT)
    yVelocity -= 1;
  else if (y < 0)
    yVelocity += 1;
}

void Node::update()
{
  k = std::sqrt(WIDTH * HEIGHT) / totalNodes;

  validLoc();

  if (xAccel > 0.5)
    xAccel = 0.1;
  else if (xAccel < -0.5)
    xAccel = -0.1;

  if (yAccel > 0.5)
    yAccel = 0.1;
  else if (yAccel < -0.5)
    yAccel = -0.1;

  xVelocity += xAccel;
  yVelocity += yAccel;
  x += xVelocity;
  y += yVelocity;
  circle.setPosition(x, y);
}

bool Node::checkCollision(float x_, float y_)
{
  return x_ >= x && x_ <= x + radius && y_ >= y && y <= y + radius;
}

float Node::getDistance(Node a)
{
  float dx = a.getX() - x;
  float dy = a.getY() - y;
  return hypot(dx, dy);
}

float Node::repulsiveForce(const Node& a)
{
  float dist = getDistance(a);
  return (k * k) / dist;
}

float Node::attractiveForce(const Node& a)
{
  float dist = getDistance(a);
  return (dist * dist) / k;
}

void Node::netForce(const Node& a)
{
  t++;
  float netForce = attractiveForce(a) - repulsiveForce(a); //attractiveForce(a);// - repulsiveForce(a);
  float angle = getAngle(a);

  // Change constant 
  xAccel -= cos(angle) * netForce;
  yAccel -= sin(angle) * netForce;
}

float Node::getAngle(Node a)
{
  float tempDX = a.getX() - x;
  float tempDY = a.getY() - y;
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

const void Node::setXAccel(float temp)
{
  xAccel = temp;
}

const void Node::setYAccel(float temp)
{
  yAccel = temp;
}




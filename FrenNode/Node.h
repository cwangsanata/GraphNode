#pragma once
/*
* Visual representation of the nodes
*/

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

#include "Friend.h"

static int totalNodes; // NSFW
static int t; // Damping

class Node
{
private:
  float radius;
  int x, y;
  float xVelocity, yVelocity;
  float xAccel, yAccel;
  float k; // Constant for calculating force
  std::string id;
  sf::Text textID;
  sf::Font font;
  sf::CircleShape circle;
  std::vector<Node> adjList; // Adjacency list implementation of graph

public:
  Node();
  Node(float, float);
  Node(const sf::Font&, float, float);
  ~Node();

  sf::CircleShape getCircle() { return circle; }
  int getX() { return x; }
  int getY() { return y; }
  int getRadius() { return radius; }
  std::string getStringID() { return id; }
  sf::Text getTextID() { return textID; }
  std::vector<Node> getAdjList() { return adjList; }

  const void setXAccel(float);
  const void setYAccel(float);

  void validLoc();
  void update();
  void addAdjacent(Node&);

  bool checkCollision(float x, float y);
  float getDistance(Node);
  float repulsiveForce(const Node&); // Universally applies
  float attractiveForce(const Node&); // Applies stronger to only nodes with edges
  void netForce(const Node&); // merge both forces together
  float getAngle(Node);
};

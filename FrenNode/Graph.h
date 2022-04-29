#pragma once

#include <vector>
#include "Node.h"

class Graph
{
private:
  std::vector<Node>* nodes;

public:
  Graph(std::vector<Node>);
  const void addNode(Node);

  void calculateForceDiagram();

};


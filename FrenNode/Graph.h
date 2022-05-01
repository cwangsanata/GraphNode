#pragma once

#include <vector>

#include "Node.h"
#include "Link.h"

class Graph
{
private:
  std::vector<Node> nodes;
  std::vector<Link> edges;

public:
  Graph();
  Graph(std::vector<Node>);

  const void addNode(Node&);
  const void addLink(Link&);
  const void connectNodes();
  const void connectNodes(Node&, Node&);
  const void connectNodes(Link);
  const void connectNodes(std::vector<Link>&);

  std::vector<Node> getNodes() { return nodes; }
  std::vector<Link> getEdges() { return edges; }
  void calculateForceDiagram();
  void update();

};


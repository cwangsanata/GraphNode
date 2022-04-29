#include "Graph.h"

Graph::Graph(std::vector<Node> nodes_)
{
  nodes = &nodes_;
}

const void Graph::addNode(Node a)
{
  (*nodes).push_back(a);
}

void Graph::calculateForceDiagram()
{
  for (int i = 0; i < (*nodes).size(); i++)
  {
    for (int j = 0; j < (*nodes).size(); j++)
    {
      if (nodes[i] != nodes[j])
        continue;
    }
  }
}





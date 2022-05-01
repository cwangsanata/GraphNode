#include "Graph.h"

Graph::Graph()
{
}

const void Graph::addNode(Node &a)
{
  nodes.push_back(a);
}

const void Graph::addLink(Link& a)
{
  edges.push_back(a);
}

const void Graph::connectNodes()
{
  for (int i = 0; i < nodes.size(); i++) {  
    std::cout << "NAME: " << nodes[i].getStringID() << " ";
    std::cout << "SIZE: " << nodes[i].getAdjList().size() << std::endl;
    for (int j = 0; j < nodes[i].getAdjList().size(); j++)
    {
      edges.push_back(Link(nodes[i], nodes[j]));
    }
  }
}

const void Graph::connectNodes(Node& a, Node& b)
{
  Link tempLink = Link(a, b);
  edges.push_back(tempLink);
}

const void Graph::connectNodes(Link a)
{
  edges.push_back(a);
}

const void Graph::connectNodes(std::vector<Link> &tempArr)
{
  edges = tempArr;
}

void Graph::calculateForceDiagram()
{
  for (int i = 0; i < nodes.size(); i++)
  {
    for (int j = 0; j < nodes.size(); j++)
    {
      if (i != j)
        continue;

      nodes[i].netForce(nodes[j]);
    }
  }
}

void Graph::update()
{
  for (int i = 0; i < nodes.size(); i++)
    nodes[i].update();

  for (int i = 0; i < edges.size(); i++)
    edges[i].update();
}
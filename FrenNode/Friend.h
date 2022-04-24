#pragma once

#include <string>
#include <vector>

class Friend
{
private:
  std::string name;
  std::vector<Friend> adjList; // Adjacency list implementation of graph

public:
  Friend();
  // ~Friend();
  void addFriend(Friend);
  void removeFriend(Friend);
  void removeFriend(std::string);
// distanceFromFriend()
//    degrees of friendship
};

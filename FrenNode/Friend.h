#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Friend
{
private:
  std::string name;
  std::vector<Friend> adjList; // Adjacency list implementation of graph

public:
  Friend();
  Friend(std::string);
  
  std::string getName() { return name; }

  void setName(std::string name_) { name = name_; }
  void addFriend(Friend);
  void removeFriend(Friend);
  void removeFriend(std::string);
  void printFriends();

  friend bool operator==(const Friend& lhs, const Friend& rhs)
  {
    if (lhs == rhs) 
      return true;

    else
      return false;
  }


 
// removeFriend()
//    removes link from friend
// degreesFromFriend()
//    degrees of friendship
};

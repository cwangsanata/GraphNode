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
  void addFriend(const Friend&);
  void removeFriend(Friend);
  void removeFriend(std::string);
  const std::vector<Friend> getFriendList();
  void printFriends();

  friend bool operator==(const Friend& lhs, const Friend& rhs)
  {
    return lhs == rhs;
  }

// degreesFromFriend()
//    degrees of friendship
};

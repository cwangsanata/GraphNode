#include "Friend.h"

Friend::Friend()
{
  name = "You";
}

Friend::Friend(std::string name_)
{
  name = name_;
}

void Friend::addFriend(Friend a)
{
  adjList.push_back(a);
}

void Friend::removeFriend(Friend a)
{
  adjList.erase(std::remove(adjList.begin(), adjList.end(), a), adjList.end());
}

void Friend::printFriends()
{
  for (Friend a : adjList)
    std::cout << a.getName() << std::endl;
}
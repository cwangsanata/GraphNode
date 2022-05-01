#include "Friend.h"

Friend::Friend()
{
  name = "You";
}

Friend::Friend(std::string name_)
{
  name = name_;
}

void Friend::addFriend(const Friend &a)
{
  adjList.push_back(a);
}

void Friend::removeFriend(Friend a)
{
  adjList.erase(std::remove(adjList.begin(), adjList.end(), a), adjList.end());
}

const std::vector<Friend> Friend::getFriendList()
{
  return adjList;
}

void Friend::printFriends()
{
  for (auto i = 0; i < adjList.size(); i++)
    std::cout << adjList[i].getName() << "\n";
}
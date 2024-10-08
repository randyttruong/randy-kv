//
// hashmap.h
//
// A hashmap implementation in C++ using probabilistic hashing.
//
// Created by Randy Truong on 8/12/24.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <vector>


class HashMap {
private:
  std::vector<std::vector<std::pair<std::string, std::string>>> map;

public:
  HashMap();

  int getSize();

  int testHashing(std::string input);
  std::string getValue(std::string input);
  int addKey(std::string input, std::string value);
  int updateKey(std::string input, std::string value);
  int deleteKey(std::string input);
  bool keyExists(std::string input);

};



#endif //HASHMAP_H

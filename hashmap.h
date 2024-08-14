/*
 * hashmap.h
 *
 * A probabilistic hashmap implementation in C++.
 *
 * Created by Randy Truong on 8/12/24.
 */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <vector>


class HashMap {
private:
  std::vector<std::string> map;

public:
  HashMap();

  int getSize();

  std::string getValue();
  int addKey(std::string input, std::string value);
  int updateKey(std::string input, std::string value);
  int deleteKey(std::string input);
};



#endif //HASHMAP_H

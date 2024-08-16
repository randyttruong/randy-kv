//
// Created by Randy Truong on 8/12/24.

#include "hashmap.h"

#include "debug.h"
#include "../include/fnv1.h"

HashMap::HashMap() {
  this->map.resize(1000);
}

int HashMap::getSize() { return this->map.size(); }

int HashMap::testHashing(std::string input) {
  uint64_t h = hash(input, 32);

  std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

  std::cout << "Here is the hashed value: " << h << std::endl;

  std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

  std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

  std::cout << "Here is the hashed value modded: " << h % 1000 << std::endl;

  std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

}

std::string HashMap::getValue() {
  return "";
}

int HashMap::addKey(std::string input, std::string value) {
  if (DEBUG_MODE) {
    std::cout << "[DEBUG] Attempting to add <" << input << ", " << value << ">" << std::endl;
  }

  uint64_t h = hash(input, 32) % this->getSize();
  std::vector<std::pair<std::string, std::string>> currBucket  = this->map[h];

  for (int i = 0; i < currBucket.size(); i++) {
    if (currBucket[i].first == input) {
      std::cerr << "[WARN] Attempted to add a key \"" << input <<
        "\" that already exists. Aborting." << std::endl;
    }
  }

  this->map[h].push_back(std::make_pair(input, value));

  if (DEBUG_MODE) {
    std::cout << "[DEBUG] Successfully added <" << input << ", " << value << ">" << std::endl;
  }

  return 0;
}

int HashMap::updateKey(std::string input, std::string value) {
  if (DEBUG_MODE) {
    std::cout << "[DEBUG] Attempting to update key \"" << input << "\" to the value \"" << value << "\" " << std::endl;
  }

  uint64_t h = hash(input, 32) % this->getSize();
  std::vector<std::pair<std::string, std::string>> currBucket = this->map[h];

  for (int i = 0; i < currBucket.size(); i++) {
    if (currBucket[i].first == input) {
      if (DEBUG_MODE) {
        std::cout << "[DEBUG] Successfully found key \"" << input << "\". Updating." << std::endl;
      }
      currBucket[i].second = value;
      return 0;
    }
  }

  if (DEBUG_MODE) {
    std::cerr << "[WARN] Unable to find key \"" << input << "\". Aborting." << std::endl;
  }

  return 1;
}

int HashMap::deleteKey(std::string input) {
  if (DEBUG_MODE) {
    std::cout << "[DEBUG] Attempting to delete key \"" << input << "\"" << std::endl;
  }

  uint64_t h = hash(input, 32) % this->getSize();
  std::vector<std::pair<std::string, std::string>> currBucket = this->map[h];

  for (int i = 0; i < currBucket.size(); i++) {
    if (currBucket[i].first == input) {
      if (DEBUG_MODE) {
        std::cout << "[DEBUG] Successfully found key \"" << input << "\". Deleting." << std::endl;
      }

      currBucket.erase(currBucket.begin() + i);
      return 0;
    }
  }

  if (DEBUG_MODE) {
    std::cerr << "[WARN] Unable to find key \"" << input << "\". Aborting." << std::endl;
  }

  return 1;
}

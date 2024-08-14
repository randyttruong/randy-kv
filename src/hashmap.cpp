//
// Created by Randy Truong on 8/12/24.

#include "hashmap.h"
#include "../include/fnv1.h"


HashMap::HashMap() {}

int HashMap::getSize() { return this->map.size(); }

std::string HashMap::getValue() {
  return "";
}

int HashMap::addKey(std::string input, std::string value) {
  uint64_t hash = hash(input);
  return 0;
}

int HashMap::updateKey(std::string input, std::string value) {
  uint64_t hash = hash(input);
  return 0;
}

int HashMap::deleteKey(std::string input) {
  uint64_t hash = hash(input);
  return 0;
}

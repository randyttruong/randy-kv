//
// Created by Randy Truong on 8/19/24.
//

#include "CommandFactory.h"

#include <iostream>
#include <string>

/**
 * @params a (source), b (target)
 *
 */
bool equalsNoCase(std::string a, std::string b) {
  size_t n = a.size();
  size_t m = b.size();

  if (n != m) return false;

  for (size_t i = 0; i < n; i++) {
    if (std::tolower(a[i]) != std::tolower(b[i])) return false;
  }

  return true;
}

CommandFactory::CommandFactory() {}

std::unique_ptr<Command> CommandFactory::makeQuery(std::string type) {
  if (equalsNoCase(type, "get")) {
    return new std::make_unique<GetCommand>();
  } else if (equalsNoCase(type, "set")) {
    return new std::make_unique<SetCommand>();
  } else if (equalsNoCase(type, "update")) {
    return new std::make_unique<UpdateCommand>();
  } else if (equalsNoCase(type, "delete")) {
    return new std::make_unique<DeleteCommand>();
  } else {
    std::cout << "[ERROR] Unexpected error. Incorrect operation." << std::endl;
  }
}

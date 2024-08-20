//
// Created by Randy Truong on 8/19/24.
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <memory>

#include "cli.h"


class CommandFactory {
private:
public:
  CommandFactory();
  std::unique_ptr<Command> makeQuery(std::string type);
};



#endif //COMMANDFACTORY_H

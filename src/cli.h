//
// Created by Randy Truong on 8/19/24.
//

#ifndef CLI_H
#define CLI_H
#include <memory>
#include <string>

#include "clicommands.h"
#include "fileparser.h"
#include <boost/program_options.hpp>

// enum class CliCommandType {
//   START,
//   INIT,
// };

class CliCommandFactory {
private:
public:
  CliCommandFactory();
  std::unique_ptr<CliCommand> makeCommand();
};

class CLI {
private:
  bool newFileFlag;

public:
  CLI();
  bool parseCommand(int argc, char* argv[]); // Argument Parser for the CLI
  bool Command(); // Argument Parser for the CLI
  bool loop(); // the main loop of the CLI

};


#endif //CLI_H

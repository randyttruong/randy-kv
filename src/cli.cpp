//
// Created by Randy Truong on 8/19/24.
//

#include "cli.h"

#include <iostream>
#include <string>
#include <vector>

#include "debug.h"
#include "executor.h"
#include "parser.h"
#include "tokenizer.h"

class HashMap;
namespace po = boost::program_options;

CLI::CLI() { this->newFileFlag = false; }
CliCommandFactory::CliCommandFactory() {};
std::unique_ptr<CliCommand> CliCommandFactory::makeCommand() {
}

// TODO: Make more sophisticated command parser tree
// TODO: Do a lot of refactoring pls :)

// Argument Parser for the CLI
bool CLI::parseCommand(int argc, char *argv[]) {
    po::variables_map vm;

    // TODO: Should this go within the CLI class?
    // Creating description for command-line arguments
    po::options_description desc("randy-kv\n\nUsage: randy-kv [file]    init storage with file\n   or: randy-kv init      new storage\n\nOptions");

    desc.add_options()
        ("help", "produce help message")
        ("filename", po::value<std::string>(), "filename to parse");

    // Create variable map to store parsed options.

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);  // Notify about the parsed options.
    }
    catch (const po::error& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    // Handle 'help' option
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    if (vm.count("init")) {
        std::cout << "got here" << std::endl;
        return 0;
    }

    if (argc < 2) {
        std::cerr
                << desc
                << std::endl;
        std::exit(1);
    }

    std::string cmd = argv[1];
    std::string filename;

    if (cmd == "start") {
      // TODO: Implement file extension checking
      filename = argv[2];
      std::cout << "Initializing" << filename << std::endl;
    } else if (cmd == "init") {
      if (vm.count("filename")) {
        filename = vm["filename"].as<std::string>();
      } else {
        filename = "output.rt";
      }
      this->newFileFlag = true;
    }

    if (DEBUG_MODE != 0) {
      std::cout << "[DEBUG] Opening file " << filename << std::endl;
    }

    if (!this->newFileFlag) {
      FileParser fp = FileParser();
      fp.setInput(filename);
      fp.parseFile();

      Tokenizer tkzr = Tokenizer(fp);

      tkzr.tokenizeInput();

      std::vector<Token> tokenStream = tkzr.getTokenStream();

      Parser parser = Parser(tkzr);
      parser.parseTokenStream();
      parser.ast.printOperatorType();

      HashMap *hm = new HashMap();
      Executor exec = Executor(parser, *hm);

      exec.executeQueries();
    }

  this->loop(); // start the main loop
}

// TODO: Maybe this should go somewhere else?
// Loop will be the REPL for the CLI
// This will turn on whenever a person consumes a data file.

// Usage: <randy_kv> <start> <filename>
bool CLI::loop() {

  // Main loop
  while (true) {
    std::cout << ">> ";
    std::string input;

    // Grab the input
    std::getline(std::cin, input);

    if (input == "exit") {
      std::cout << "Exiting program." << std::endl;
      break;
    } else {
      std::vector<std::string> commandStream;

      const size_t length = input.length();
      int pos = 0;

      // Removing whitespace
      while (pos < length && std::isspace(input[pos])) pos++;

      if (pos >= length) {
        std::cout << "No input detected." << std::endl;
        continue;
      }
    }
  }

}
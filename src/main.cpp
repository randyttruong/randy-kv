#include <iostream>
#include <vector>

#include "analyzer.h"
#include "cli.h"
#include "fileparser.h"
#include "parser.h"
#include "tokenizer.h"
#include "debug.h"
#include "executor.h"
#include "hashmap.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char *argv[]) {
    CLI *cli = new CLI();

    cli->parseCommand(argc, argv);


    // std::cout << "========================"
    //         << "========================"
    //         << "========================"
    //         << std::endl;
    //
    // std::cout << "[DEBUG] Testing out hashing " << std::endl;
    //
    // std::cout << "========================"
    //         << "========================"
    //         << "========================"
    //         << std::endl;
    //
    // hm->testHashing("swag");
    // hm->testHashing("swag");
    // hm->testHashing("1234");
    // hm->testHashing("test");
    //
    return 0;
}

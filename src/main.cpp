#include <iostream>
#include <vector>

#include "fileparser.h"
#include "parser.h"
#include "tokenizer.h"
#include "debug.h"
#include "hashmap.h"

int main(int argc, char *argv[]) {
    std::string filename;

    if (argc != 2) {
        std::cerr
             << "[ERROR] No filename provided. Exiting."
             << std::endl;
        if (DEBUG_MODE == 0) std::exit(1);
    }

    filename = argv[1];

    if (DEBUG_MODE != 0) {
        std::cout << "[DEBUG] Opening file " << filename << std::endl;
    }

    FileParser fp = FileParser();
    fp.setInput(filename);
    fp.parseFile();

    Tokenizer tkzr = Tokenizer(fp);

    tkzr.tokenizeInput();

   std::vector<Token> tokenStream = tkzr.getTokenStream();

    for (const auto &[type, tokenType, value]: tokenStream) {
      std::cout << "========================"
          << "========================"
          << "========================"
          << std::endl;
      std::cout << tokenType + " " + value << std::endl;
      std::cout << "========================"
          << "========================"
          << "========================"
          << std::endl;
    }

    Parser parser = Parser(tkzr);
    parser.parseTokenStream();
    parser.ast.printOperatorType();

    std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

    std::cout << "[DEBUG] Testing out hashing " << std::endl;

    std::cout << "========================"
            << "========================"
            << "========================"
            << std::endl;

    HashMap *hm = new HashMap();

    hm->testHashing("swag");
    hm->testHashing("swag");
    hm->testHashing("1234");
    hm->testHashing("test");

    return 0;
}

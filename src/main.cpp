#include <iostream>
#include <vector>

#include "fileparser.h"
#include "parser.h"
#include "tokenizer.h"
#include "debug.h"

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

    for (size_t i = 0; i < fp.getInputStream().size(); i++) {
        std::string currTest = std::to_string(i);
        std::cout << "=======" << " TEST " + currTest + " " << "=======" << std::endl;
        std::cout << "String: " << fp.getInputStream()[i] << std::endl;
        Tokenizer tokenizer = Tokenizer(fp.getInputStream()[i], 0);
        tokenizer.tokenize();
        std::vector<Token> tokenStream = tokenizer.getTokenStream();

        for (const auto &[type, tokenType, value]: tokenStream) {
            std::cout << tokenType + " " + value << std::endl;
        }

        Parser parser = Parser(tokenStream);
        parser.parseTokenStream();
        parser.ast.printOperatorType();
    }
    return 0;
}

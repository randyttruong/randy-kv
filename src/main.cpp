#include <iostream>
#include <vector>

#include "parser.h"
#include "tokenizer.h"

int main() {
    const std::vector<std::string> testStrings = {
        "get test1 test1",
        "set test test",
        "set \"this\" \"test\"",
        "update swag \"here\"",
        "update swag swag ",

    };

    for (size_t i = 0; i < testStrings.size(); i++) {
        std::string currTest = std::to_string(i);
        std::cout << "=======" << " TEST " + currTest + " " << "=======" << std::endl;
        std::cout << "String: " << testStrings[i] << std::endl;
        Tokenizer tokenizer = Tokenizer(testStrings[i], 0);
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

#include <iostream>
#include <vector>

#include "tokenizer.h"

int main() {

    const std::vector<std::string> testStrings = {
        "get test1 test1",
        "save test test",
        "set \"this\" \"test\""
    };

    std::cout << "set \"these\" nuts" << std::endl;

    for (size_t i = 0; i < testStrings.size(); i++) {
        std::string currTest = std::to_string(i);
        std::cout << "=======" << " TEST " + currTest + " " << "=======" << std::endl ;
        std::vector<Token> tokens;
        Tokenizer tokenizer = Tokenizer(testStrings[i], 0);

        for (int i = 0; i < 3; i++) {
            tokens.push_back(tokenizer.getNextToken());
        }

        for (const auto &[type, tokenType, value]: tokens) {
            std::cout << tokenType + " " + value << std::endl;
        }
    }


    return 0;
}

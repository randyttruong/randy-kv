#include <iostream>
#include <vector>

#include "parser.h"
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
        Tokenizer tokenizer = Tokenizer(testStrings[i], 0);
        tokenizer.tokenize();
        std::vector<Token> tokenStream = tokenizer.getTokenStream();

        for (const auto &[type, tokenType, value]: tokenStream) {
            std::cout << tokenType + " " + value << std::endl;
        }

        Parser parser = Parser(tokenStream);
        parser.parseTokenStream();

        OperatorType type = parser.ast.getOperatorType();
        std::string final;

        switch (type) {
            case OperatorType::GET:
                final = "get";
                break;
            case OperatorType::SET:
                final = "set";
                break;
            case OperatorType::DELETE:
                final = "delete";
                break;
            default:
                final = "";
                break;
        }

        std::cout << "OPERATOR TYPE " + final << std::endl;



    }



    return 0;
}

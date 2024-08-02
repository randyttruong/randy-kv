//
// Created by Randy Truong on 7/31/24.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    LITERAL,
    END,
    INVALID
};

struct Token {
    TokenType type;
    std::string tokenType;
    std::string value;
};

class Tokenizer {
private:
    std::string input;
    size_t pos;

public:
    Tokenizer(std::string input, size_t pos);

    Token getNextToken();
};

#endif //TOKENIZER_H

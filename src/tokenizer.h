//
// Created by Randy Truong on 7/31/24.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

#include "fileparser.h"

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
    FileParser fileParser;
    std::vector<Token> TokenStream;
    uint64_t pos;

public:
    Tokenizer(FileParser fileParser);
    void tokenize(std::string input);
    Token getNextToken(std::string input);

    void tokenizeInput();

    std::vector<Token> getTokenStream();
    void pushToTokenStream(Token input);
};

#endif //TOKENIZER_H

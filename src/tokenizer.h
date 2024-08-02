//
// Created by Randy Truong on 7/31/24.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

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
    std::vector<Token> TokenStream;

public:
    Tokenizer(std::string input, size_t pos);
    void tokenize();
    Token getNextToken();
    std::vector<Token> getTokenStream();
    void pushToTokenStream(Token input);
};

#endif //TOKENIZER_H

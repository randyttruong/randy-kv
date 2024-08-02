//
// Created by Randy Truong on 7/31/24.
//

#ifndef PARSER_H
#define PARSER_H
#include <vector>

#include "ast.h"
#include "tokenizer.h"

class Parser {
private:
    std::vector<Token> TokenStream;

public:
    AbstractSyntaxTree ast;

    Parser(std::vector<Token> TokenStream);
    void parseTokenStream();
};



#endif //PARSER_H

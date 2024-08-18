//
// parser.h
//
// Implementation of a TokenStream parser and syntactic analyzer
// in C++.
//
// Fields:
// - TODO
// Getter/Setter Methods:
// - TODO
// Functional Methods:
// - TODO
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
    Tokenizer tokenizer;
    std::vector<AbstractSyntaxTree> queries;

public:
    AbstractSyntaxTree ast;

    Parser(const Tokenizer &tokenizer);
    void parseTokenStream();
    std::vector<AbstractSyntaxTree> getQueries();
};



#endif //PARSER_H

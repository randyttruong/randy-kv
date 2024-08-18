//
// analyzer.h
//
// Implementation of an AbstractSyntaxTree parser in C++.
//
// Fields:
// - TODO
// Getter/Setter Methods:
// - TODO
// Functional Methods:
// - TODO
//
// Created by Randy Truong on 08/02/24.
//


#ifndef ANALYZER_H
#define ANALYZER_H
#include "ast.h"
#include "parser.h"


class Analyzer {
private:
    Parser parser;
    AbstractSyntaxTree ast;
public:
    Analyzer();
    void analyze();
};



#endif //ANALYZER_H
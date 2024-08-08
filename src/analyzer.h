//
// Created by Randy Truong on 8/2/24.
//

#ifndef ANALYZER_H
#define ANALYZER_H
#include "ast.h"


class Analyzer {
private:
    AbstractSyntaxTree ast;
public:
    Analyzer();
    void analyze();
};



#endif //ANALYZER_H
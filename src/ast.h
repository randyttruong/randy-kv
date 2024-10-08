//
// Created by Randy Truong on 8/1/24.
//

#ifndef AST_H
#define AST_H
#include "node.h"
#include "tokenizer.h"


class AbstractSyntaxTree {
private:
    OperatorType type;
    GET getQuery;
    SET setQuery;
    UPDATE updateQuery;
    DELETE deleteQuery;

public:
    AbstractSyntaxTree();
    void setGetQuery(GET query);
    void setSetQuery(SET query);
    void setUpdateQuery(UPDATE query);
    void setDeleteQuery(DELETE query);

    GET& getGetQuery();
    SET& getSetQuery();
    UPDATE& getUpdateQuery();
    DELETE& getDeleteQuery();
    OperatorType getOperatorType();
    void printOperatorType() const;
};



#endif //AST_H

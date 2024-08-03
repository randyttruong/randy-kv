//
// Created by Randy Truong on 8/1/24.
//

#include "ast.h"

#include <iostream>

AbstractSyntaxTree::AbstractSyntaxTree() {
    this->type = OperatorType::VOID;
}

void AbstractSyntaxTree::setGetQuery(GET query) {
    this->getQuery = query;
    this->type = OperatorType::GET;
}

void AbstractSyntaxTree::setSetQuery(SET query) {
    this->setQuery = query;
    this->type = OperatorType::SET;
}

void AbstractSyntaxTree::setDeleteQuery(DELETE query) {
    this->deleteQuery = query;
    this->type = OperatorType::DELETE;
}

GET& AbstractSyntaxTree::getGetQuery() { return this->getQuery; }

SET& AbstractSyntaxTree::getSetQuery() { return this->setQuery; }

DELETE& AbstractSyntaxTree::getDeleteQuery() { return this->deleteQuery; }

OperatorType AbstractSyntaxTree::getOperatorType() { return this->type; }

void AbstractSyntaxTree::printOperatorType() const {
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



//
// Created by Randy Truong on 8/1/24.
//

#include "ast.h"

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

GET AbstractSyntaxTree::getGetQuery() { return this->getQuery; }

SET AbstractSyntaxTree::getSetQuery() { return this->setQuery; }

DELETE AbstractSyntaxTree::getDeleteQuery() { return this->deleteQuery; }

OperatorType AbstractSyntaxTree::getOperatorType() { return this->type; }



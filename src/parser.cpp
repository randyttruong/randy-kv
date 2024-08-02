//
// Created by Randy Truong on 7/31/24.
//

#include "parser.h"

#include <iostream>
#include <set>

#include "node.h"

Parser::Parser(std::vector<Token> TokenStream): TokenStream(TokenStream), ast() {
    this->ast = AbstractSyntaxTree();
}

void Parser::parseTokenStream() {
    for (Token currToken: TokenStream) {
        const auto &[type, tokenType, value]= currToken;

        switch (type) {
            case TokenType::KEYWORD:
                    if (value == "get") {
                        GET getQuery = GET();
                        this->ast.setGetQuery(getQuery);
                    }
                    else if (value == "set") {
                        SET setQuery = SET();
                        this->ast.setSetQuery(setQuery);
                    }
                    else if (value == "delete") {
                        DELETE delQuery = DELETE();
                        this->ast.setDeleteQuery(delQuery);
                    }
                break;

            case TokenType::IDENTIFIER:
                // If no operator, then break
                if (this->ast.getOperatorType() == OperatorType::VOID) {
                    std::cout << "[ERROR] No operator found. Failing." << std::endl;
                    exit(1);
                }
                switch (this->ast.getOperatorType()) {
                    case OperatorType::GET:
                        this->ast.getGetQuery().setIdentifier(currToken);
                        break;
                    case OperatorType::SET:
                        this->ast.getSetQuery().setIdentifier(currToken);
                        break;
                    case OperatorType::DELETE:
                        this->ast.getDeleteQuery().setIdentifier(currToken);
                        break;
                    default:
                        break;
                }
                break;

            case TokenType::LITERAL:
                if (this->ast.getOperatorType() == OperatorType::GET
                    || this->ast.getOperatorType() == OperatorType::DELETE
                    || this->ast.getOperatorType() == OperatorType::VOID) {
                    std::cout << "[ERROR] Token cannot be literal." << std::endl;
                    exit(1);
                }
                this->ast.getSetQuery().setLiteral(currToken);
                break;

            default:
                break;
        }
    }
}

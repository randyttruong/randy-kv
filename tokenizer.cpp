//
// Created by Randy Truong on 7/31/24.
//

#include "tokenizer.h"

#include <iostream>
#include <vector>

Tokenizer::Tokenizer(std::string input, size_t pos): input(std::move(input)), pos(pos) {}

Token Tokenizer::getNextToken() {
    Token finalToken;
    std::string finalString;

    const size_t length = input.length();

    while (pos < length && std::isspace(input[pos])) pos++;

    if (pos == length) {
        finalToken.type = TokenType::END;
        finalToken.value = "";
    }

    // Keywords + Identifiers
    if (isalnum(input[pos])) {
        while (isalnum(input[pos]) && pos < length) {
            finalString += std::tolower(input[pos]);
            pos++;
        }

        if (finalString == "get" || finalString == "set"
            || finalString == "delete") {
            finalToken.type = TokenType::KEYWORD;
            finalToken.tokenType = "keyword";
        }
        else {
            finalToken.type = TokenType::IDENTIFIER;
            finalToken.tokenType = "identifier";
        }

        finalToken.value = finalString;
        return finalToken;
    }

    // String Literals
    if (input[pos] == '"') {

        finalToken.type = TokenType::LITERAL;
        finalToken.tokenType = "literal";
        finalString += input[pos];
        pos++;

        while (pos < length) {
            if (input[pos] == '"') {
                finalString += input[pos];
                pos++;
                break;
            }
            finalString += std::tolower(input[pos]);
            pos++;
        }

        finalToken.value = finalString;
        return finalToken;
    }

    // Otherwise, invalid
    finalToken.type = TokenType::INVALID;
    finalToken.tokenType = "invalid";
    finalToken.value = "-1";

    return finalToken;
}
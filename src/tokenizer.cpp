//
// Created by Randy Truong on 7/31/24.
//

#include "tokenizer.h"

#include <iostream>
#include <vector>

Tokenizer::Tokenizer(FileParser fileParser): fileParser(fileParser) {
    this->pos = 0;
}

Token Tokenizer::getNextToken(std::string input) {
    Token finalToken;
    std::string finalString;

    const size_t length = input.length();

    while (pos < length && std::isspace(input[pos])) pos++;

    if (pos >= length) {
        finalToken.type = TokenType::END;
        finalToken.tokenType = "end";
        finalToken.value = "";
        return finalToken;
    }

    // Keywords + Identifiers
    if (isalnum(input[pos])) {
        while (isalnum(input[pos]) && pos < length) {
            finalString += std::tolower(input[pos]);
            pos++;
        }

        if (finalString == "get" || finalString == "set"
            || finalString == "update" || finalString == "delete") {
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
    pos++;

    return finalToken;
}

void Tokenizer::tokenizeInput() {
    std::vector<std::string> input = this->fileParser.getInputStream();

    for (size_t i = 0; i < input.size(); i++) {
        this->pos = 0;
        tokenize(input[i]);
    }

}

void Tokenizer::tokenize(std::string input) {

    while (true) {
        Token currentToken = getNextToken(input);
        pushToTokenStream(currentToken);
        if (currentToken.type == TokenType::END) return;
    };

}

std::vector<Token> Tokenizer::getTokenStream() { return this->TokenStream; }
void Tokenizer::pushToTokenStream(Token input) {
    TokenStream.push_back(input);
}


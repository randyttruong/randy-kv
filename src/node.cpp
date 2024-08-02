//
// Created by Randy Truong on 8/1/24.
//

#include "node.h"

Identifier::Identifier(IdentifierType type, std::string name): type(type), name(name) {}

NumericalLiteral::NumericalLiteral(int value): value(value) {}
void NumericalLiteral::setValue(int value) { this->value = value; }

FloatingLiteral::FloatingLiteral(float value): value(value) {}
void FloatingLiteral::setValue(float value) { this->value = value; }

StringLiteral::StringLiteral(std::string value): value(value) {}
void StringLiteral::setValue(std::string value) { this->value = value; }

Identifier GET::getIdentifier() { return this->identifier; }

void GET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier(IdentifierType::VARIABLE, value);
    this->identifier = identifier;
}

void  SET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier(IdentifierType::VARIABLE, value);
    this->identifier = identifier;
}

void  SET::setLiteral(Token literalToken) {
    const auto &[type, tokenType, value] = literalToken;

    if (type != TokenType::LITERAL) {
        exit(1);
    }

    // TODO: Add support for non-alpha literals

    this->literal = StringLiteral(value);
}

int DELETE::addIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier(IdentifierType::VARIABLE, value);

    this->identifiers.push_back(identifier);
}





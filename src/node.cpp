//
// Created by Randy Truong on 8/1/24.
//

#include "node.h"

Identifier::Identifier() {
    this->type = IdentifierType::VOID;
    this->name = "";
}

void Identifier::setType(IdentifierType type) { this->type = type; }

void Identifier::setName(std::string name) { this->name = name; }


NumericalLiteral::NumericalLiteral() {
    this->value = 0;
}

void NumericalLiteral::setValue(int value) { this->value = value; }

FloatingLiteral::FloatingLiteral() {
    this->value = 0.0;
}
void FloatingLiteral::setValue(float value) { this->value = value; }

StringLiteral::StringLiteral() {
    this->value = "";
}
void StringLiteral::setValue(std::string value) { this->value = value; }

Identifier GET::getIdentifier() { return this->identifier; }

GET::GET() { this->identifier = Identifier(); }
SET::SET() { this->identifier = Identifier(); this->literal = Literal(); }
DELETE::DELETE() { }

Operator::Operator() { this->type = OperatorType::VOID; }
OperatorType Operator::getType() { return this->type; };

void GET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
}

void SET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
}

void SET::setLiteral(Token literalToken) {
    const auto &[type, tokenType, value] = literalToken;

    if (type != TokenType::LITERAL) {
        exit(1);
    }

    // TODO: Add support for non-alpha literals

    StringLiteral literal = StringLiteral();
    literal.setValue(value);
    this->literal = literal;
}

void DELETE::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifiers.push_back(identifier);
}
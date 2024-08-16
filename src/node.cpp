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


GET::GET() {
    this->identifier = Identifier();
    this->identifierSetFlag = 0;
}

void GET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
    setIdSetFlag();
}

int GET::getIdSetFlag() { return this->identifierSetFlag; }
void GET::setIdSetFlag() { this->identifierSetFlag = 1 ; }

SET::SET() {
    this->identifier = Identifier();
    this->literal = Literal();
    this->identifierSetFlag = 0;
    this->literalSetFlag = 0;
}
Literal SET::getLiteral() { return this->literal; }

void SET::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
    this->identifierSetFlag = 1;
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
    setLitSetFlag();
}


int SET::getLitSetFlag() { return this->literalSetFlag; }

void SET::setLitSetFlag() { this->identifierSetFlag = 1; }

UPDATE::UPDATE() {
    this->identifier = Identifier();
    this->literal = Literal();
    this->identifierSetFlag = 0;
    this->literalSetFlag = 0;
}

Identifier UPDATE::getIdentifier() { return this->identifier; }

Literal UPDATE::getLiteral() { return this->literal; }

void UPDATE::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
    setLitSetFlag();
}

void UPDATE::setLiteral(Token literalToken) {
    const auto &[type, tokenType, value] = literalToken;

    if (type != TokenType::LITERAL) {
        exit(1);
    }

    // TODO: Add support for non-alpha literals

    StringLiteral literal = StringLiteral();
    literal.setValue(value);
    this->literal = literal;
    setLitSetFlag();
}

int UPDATE::getIdSetFlag() { return this->identifierSetFlag; }

void UPDATE::setIdSetFlag() { this->identifierSetFlag = 1; }

int UPDATE::getLitSetFlag() { return this->literalSetFlag; }

void UPDATE::setLitSetFlag() { this->identifierSetFlag = 1; }

int SET::getIdSetFlag() { return this->identifierSetFlag; }

void SET::setIdSetFlag() { this->identifierSetFlag = 1; }

Identifier SET::getIdentifier() { return this->identifier; }

DELETE::DELETE() { }

void DELETE::setIdentifier(Token identifierToken) {
    const auto &[type, tokenType, value] = identifierToken;

    if (type != TokenType::IDENTIFIER) {
        exit(1);
    }

    Identifier identifier = Identifier();
    identifier.setType(IdentifierType::VARIABLE);
    identifier.setName(value);
    this->identifier = identifier;
    this->setIdFlag();
}

Identifier DELETE::getIdentifier() { return this->identifier; }

void DELETE::setIdFlag() { this->identifierSetFlag = 1; }

int DELETE::getIdFlag() { return this->identifierSetFlag; }


Operator::Operator() { this->type = OperatorType::VOID; }
OperatorType Operator::getType() { return this->type; };


//
// Created by Randy Truong on 8/1/24.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

#include "tokenizer.h"


class ASTNode {
public:
    virtual ~ASTNode() = default;
};

enum class IdentifierType {
    VARIABLE
};

class Identifier: public ASTNode {
private:
    IdentifierType type;
    std::string name;

public:
    Identifier(IdentifierType type, std::string name);
};

enum class LiteralType {
    NUMERICAL,
    FLOATING,
    STRING
};

class Literal: public ASTNode {
};

class NumericalLiteral: public Literal {
private:
    int value;
public:
    NumericalLiteral(int value);

    void setValue(int value);
};

class FloatingLiteral: public Literal {
private:
    float value;
public:
    FloatingLiteral(float value);
    void setValue(float value);
};

class StringLiteral: public Literal {
private:
    std::string value;
public:
    StringLiteral(std::string value);
    void setValue(std::string value);
};

enum class OperatorType {
    GET,
    SET,
    DELETE
};

class GET: public ASTNode {
private:
    Identifier identifier;

public:
    GET();

    Identifier getIdentifier();
    void setIdentifier(Token identifierToken);

};

class SET: public ASTNode {
private:
    Identifier identifier;
    Literal literal;

public:
    SET();

    Identifier getIdentifier();
    Literal getLiteral();

    void setIdentifier(Token identifierToken);
    void setLiteral(Token literalToken);
};

class DELETE: public ASTNode {
private:
    std::vector<Identifier> identifiers;

public:
    DELETE();

    int addIdentifier(Token identifier);
};



#endif //NODE_H

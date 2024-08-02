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
    VARIABLE,
    VOID
};

class Identifier: public ASTNode {
private:
    IdentifierType type;
    std::string name;

public:
    Identifier();
    void setType(IdentifierType type);
    void setName(std::string name);
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
    NumericalLiteral();
    void setValue(int value);
};

class FloatingLiteral: public Literal {
private:
    float value;
public:
    FloatingLiteral();
    void setValue(float value);
};

class StringLiteral: public Literal {
private:
    std::string value;
public:
    StringLiteral();
    void setValue(std::string value);
};

enum class OperatorType {
    GET,
    SET,
    DELETE,
    VOID
};

class Operator  {
private:
    OperatorType type;

public:
    Operator();
    OperatorType getType();
};

class GET: private  Operator {
private:
    Identifier identifier;

public:
    GET();

    Identifier getIdentifier();
    void setIdentifier(Token identifierToken);

};

class SET: public Operator {
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

class DELETE: public Operator {
private:
    std::vector<Identifier> identifiers;

public:
    DELETE();

    void setIdentifier(Token identifierToken);
};



#endif //NODE_H

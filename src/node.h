//
// node.h
//
// Implementation of the various nodes for an abstract syntax tree.
//
// Fields:
// - TODO
//
// Getter/Setter Methods:
// - TODO
//
// Functional Methods:
// - TODO
//
// Created by Randy Truong on 7/31/24.
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

    IdentifierType getType();
    std::string getName();
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
    UPDATE,
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
    int identifierSetFlag;

public:
    GET();

    Identifier getIdentifier();
    void setIdentifier(Token identifierToken);
    int getIdSetFlag();
    void setIdSetFlag();
};

class SET: public Operator {
private:
    Identifier identifier;
    Literal literal;
    int identifierSetFlag;
    int literalSetFlag;

public:
    SET();

    Identifier getIdentifier();
    Literal getLiteral();

    void setIdentifier(Token identifierToken);
    void setLiteral(Token literalToken);

    int getIdSetFlag();
    void setIdSetFlag();

    int getLitSetFlag();
    void setLitSetFlag();
};

class UPDATE: public Operator {
private:
    Identifier identifier;
    Literal literal;
    int identifierSetFlag;
    int literalSetFlag;

public:
    UPDATE();

    Identifier getIdentifier();
    Literal getLiteral();

    void setIdentifier(Token identifierToken);
    void setLiteral(Token literalToken);

    int getIdSetFlag();
    void setIdSetFlag();

    int getLitSetFlag();
    void setLitSetFlag();
};

class DELETE: public Operator {
private:
    Identifier identifier;
    int identifierSetFlag;

public:
    DELETE();

    void setIdentifier(Token identifierToken);
    Identifier getIdentifier();

    void setIdFlag();
    int getIdFlag();
};



#endif //NODE_H

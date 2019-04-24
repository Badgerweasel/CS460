//
// Created by Ali A. Kooshesh on 2/5/19.
//

#ifndef EXPRINTER_STATEMENTS_HPP
#define EXPRINTER_STATEMENTS_HPP

#include <iostream>
#include <vector>

#include "Expr.hpp"
#include "SymTab.hpp"

// The Statement (abstract) class serves as a super class for all statements that
// are defined in the language. Ultimately, statements have to be evaluated.
// Therefore, this class defines evaluate, a pure-virtual function to make
// sure that all subclasses of Statement provide an implementation for this
// function.

class Statement {
public:
    Statement();
    ~Statement();

    virtual void print() = 0;
    virtual void evaluate(SymTab &symTab) = 0;
    void setIndentLevel(int indent) { indentLevel = indent; }
    int getIndentLevel() { return indentLevel; }

private:
    int indentLevel;

};


// Statements is a collection of Statement. For example, all statements in a function
// can be represented by an instance of Statements.

class Statements {
public:
    Statements();
    ~Statements();

    void addStatement(Statement *statement);
    void evaluate(SymTab &symTab);

    void print();

private:
    std::vector<Statement *> _statements;
};

// AssignmentStatement represents the notion of an lValue having been assigned an rValue.
// The rValue is an expression.

class AssignmentStatement : public Statement {
public:
    AssignmentStatement();
    ~AssignmentStatement();
    AssignmentStatement(std::string lhsVar, ExprNode *rhsExpr);

    std::string &lhsVariable();
    ExprNode *&rhsExpression();

    virtual void evaluate(SymTab &symTab);
    virtual void print();

private:
    std::string _lhsVariable;
    ExprNode *_rhsExpression;
};

class PrintStatement : public Statement {
public:
    PrintStatement();
    ~PrintStatement();
    PrintStatement(std::vector<Token> mess);

    virtual void evaluate(SymTab &symTab);
    virtual void print();

private:
    std::vector<Token> message;
};

class ForStatement : public Statement {
public:
    ForStatement();
    ~ForStatement();
    ForStatement(Token tok, int up, Statements *b);
    ForStatement(Token tok, int low, int up, Statements *b);
    ForStatement(Token tok, int low, int up, int incr, Statements *b);

    virtual void evaluate(SymTab &symTab);
    virtual void print();
    bool range();

private:
    int lower, upper, increment;
    bool initLow, initUpper, initIncrement;
    Token name;
    Statements *body;
};

class IfNode : public Statement{
public:
    IfNode();
    ~IfNode();
    IfNode(ExprNode *rel, Statements *bod);

    virtual void evaluate(SymTab &symTab);
    virtual  void print();
    bool evaluated();

private:
    ExprNode *relNode;
    Statements *body;
    bool evaluatedTrue;

};

class IfStatement : public Statement {
public:
    IfStatement();
    ~IfStatement();
    IfStatement(std::vector<IfNode*> ifs);

    virtual void evaluate(SymTab &symTab);
    virtual  void print();

private:
    std::vector<IfNode*> body;
};



#endif //EXPRINTER_STATEMENTS_HPP

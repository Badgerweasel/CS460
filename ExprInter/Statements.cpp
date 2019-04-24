//
// Created by Ali A. Kooshesh on 2/5/19.
//

#include "Statements.hpp"
#include "SymTab.hpp"

// Statement
Statement::Statement() {}

Statement::~Statement() {}

// Statements

Statements::Statements() {}

Statements::~Statements() {
    for(auto s: _statements)
        delete s;
}

void Statements::addStatement(Statement *statement) { _statements.push_back(statement); }

void Statements::print() {
    for (auto s: _statements)
        s->print();
}

void Statements::evaluate(SymTab &symTab) {
    for (auto s: _statements) {
        s->evaluate(symTab);
    }
}

// AssignmentStatement

AssignmentStatement::AssignmentStatement() : _lhsVariable{""}, _rhsExpression{nullptr} {}

AssignmentStatement::~AssignmentStatement() {
    delete _rhsExpression;
}

AssignmentStatement::AssignmentStatement(std::string lhsVar, ExprNode *rhsExpr):
        _lhsVariable{lhsVar}, _rhsExpression{rhsExpr} {}

void AssignmentStatement::evaluate(SymTab &symTab) {
    if(StringNode* tempNode = dynamic_cast<StringNode*>(rhsExpression()))
    {
        //std::string rhs = tempNode->evaluate2(symTab);
        StringDescriptor *val = dynamic_cast<StringDescriptor*>(tempNode->evaluate(symTab));
        symTab.setValueFor(lhsVariable(), val);
    }
    else {
        NumberDescriptor *rhs = dynamic_cast<NumberDescriptor*>(rhsExpression()->evaluate(symTab));

        symTab.setValueFor(lhsVariable(), rhs);
    }
}

std::string &AssignmentStatement::lhsVariable() {
    return _lhsVariable;
}

ExprNode *&AssignmentStatement::rhsExpression() {
    return _rhsExpression;
}

void AssignmentStatement::print() {
    std::cout << _lhsVariable << " = ";
    _rhsExpression->print();
    std::cout << std::endl;
}


//Print Statement
PrintStatement::PrintStatement() : message{} {}

PrintStatement::PrintStatement(std::vector<Token> mess){
    for(unsigned i = 0; i < mess.size(); i++){
        message.push_back(mess[i]);
    }
}

//this is a mess and I will hopefully clean it up a bit, it works though
void PrintStatement::evaluate(SymTab &symTab) {
    bool first = true;
    for(unsigned i = 0; i < message.size(); i++){
        if(first)
        {
            if(message[i].isString()){
                message[i].print();
            }
            else if(message[i].isWholeNumber())
            {
                if(message[i + 1].isAdditionOperator())
                {
                    int sum = message[i].getWholeNumber();
                    i += 2;
                    if(message[i].isWholeNumber())
                    {
                        sum += message[i].getWholeNumber();
                    }
                    else if(message[i].isName())
                    {
                        sum += dynamic_cast<NumberDescriptor*>(symTab.getValueFor(message[i].getName()))->value.intValue;
                    }
                    std::cout << sum;
                }
                else {
                    message[i].print();
                }
            }
            else
            {
                TypeDescriptor *nDesc = symTab.getValueFor(message[i].getName());
                if(message.size() > 1 && message[i+1].isAdditionOperator())
                {
                    if(nDesc->type() == TypeDescriptor::INTEGER) {
                        int sum = dynamic_cast<NumberDescriptor *>(nDesc)->value.intValue;
                        i += 2;
                        if (message[i].isWholeNumber()) {
                            sum += message[i].getWholeNumber();
                        } else if (message[i].isName()) {
                            sum += dynamic_cast<NumberDescriptor *>(symTab.getValueFor(
                                    message[i].getName()))->value.intValue;
                        }
                        std::cout << sum;
                    }
                    else{
                        std::string sum = dynamic_cast<StringDescriptor *>(nDesc)->value;
                        i += 2;
                        if (message[i].isString()) {
                            sum += message[i].getString();
                        } else if (message[i].isName()) {
                            sum += dynamic_cast<StringDescriptor *>(symTab.getValueFor(message[i].getName()))->value;
                        }
                        std::cout << sum;
                    }
                }
                else {
                    if (nDesc->type() == TypeDescriptor::INTEGER)

                        std::cout << dynamic_cast<NumberDescriptor *>(nDesc)->value.intValue;
                    else if (nDesc->type() == TypeDescriptor::STRING) {
                        std::cout << dynamic_cast<StringDescriptor *>(nDesc)->value;
                    }
                }
            }
        }
        else if(message[i].symbol() == ',')
        {
            i++;
            if(message[i].isWholeNumber())
            {
                if(message[i + 1].isAdditionOperator())
                {
                    int sum = message[i].getWholeNumber();
                    i += 2;
                    if(message[i].isWholeNumber())
                    {
                        sum += message[i].getWholeNumber();
                    }
                    else if(message[i].isName())
                    {
                        sum += dynamic_cast<NumberDescriptor*>(symTab.getValueFor(message[i].getName()))->value.intValue;
                    }
                    std::cout << sum;
                }
                else {
                    message[i].print();
                }
            }
            else if(message[i].isString())
            {
                message[i].print();
            }
            else{
                TypeDescriptor *nDesc = symTab.getValueFor(message[i].getName());
                if (message.size() > i + 1 && message[i + 1].isAdditionOperator()) {
                    if(nDesc->type() == TypeDescriptor::INTEGER) {
                        int sum = dynamic_cast<NumberDescriptor *>(nDesc)->value.intValue;
                        i += 2;
                        if (message[i].isWholeNumber()) {
                            sum += message[i].getWholeNumber();
                        } else if (message[i].isName()) {
                            sum += dynamic_cast<NumberDescriptor *>(symTab.getValueFor(
                                    message[i].getName()))->value.intValue;
                        }
                        std::cout << sum;
                    }
                    else{
                        std::string sum = dynamic_cast<StringDescriptor *>(nDesc)->value;
                        i += 2;
                        if (message[i].isString()) {
                            sum += message[i].getString();
                        } else if (message[i].isName()) {
                            sum += dynamic_cast<StringDescriptor *>(symTab.getValueFor(message[i].getName()))->value;
                        }
                        std::cout << sum;
                    }
                } else {
                    if (nDesc->type() == TypeDescriptor::INTEGER)

                        std::cout << dynamic_cast<NumberDescriptor *>(nDesc)->value.intValue;
                    else if (nDesc->type() == TypeDescriptor::STRING) {
                        std::cout << dynamic_cast<StringDescriptor *>(nDesc)->value;
                    }
                }
            }

        }
        first = false;
    }
    std::cout << std::endl;
}

void PrintStatement::print() {
    std::cout << "print ";
    for(unsigned i = 0; i < message.size(); i++){
        message[i].print();
    }
    std::cout << std::endl;
}

//for statement
ForStatement::ForStatement() : lower{0}, upper{-1}, increment{-1}, initLow{false}, initUpper{false}, initIncrement{false}, body{nullptr}{}

ForStatement::~ForStatement() {
    delete body;
}
//three different constructors depending on how many numbers were given to range
ForStatement::ForStatement(Token tok, int up, Statements *b) :
        name{tok}, lower{0}, upper{up}, initLow{false}, initUpper{true}, initIncrement{false}, body{b}{}

ForStatement::ForStatement(Token tok, int low, int up, Statements *b) :
        name{tok}, lower{low}, upper{up}, initLow{true}, initUpper{true}, initIncrement{false}, body{b}{}

ForStatement::ForStatement(Token tok, int low, int up, int incr, Statements *b) :
        name{tok}, lower{low}, upper{up}, increment{incr}, initLow{true}, initUpper{true}, initIncrement{true}, body{b}{}

void ForStatement::evaluate(SymTab &symTab) {
    int initLower = lower;  //initLower is used so that after the for loop executes lower can be reset to its original value so that nested loops will work
    NumberDescriptor *typeDesc = new NumberDescriptor(TypeDescriptor::INTEGER);
    typeDesc->value.intValue = lower;
    symTab.setValueFor(name.getName(), typeDesc);
    while(range()){
        body->evaluate(symTab);
        typeDesc = new NumberDescriptor(TypeDescriptor::INTEGER);
        typeDesc->value.intValue = lower;
        symTab.setValueFor(name.getName(), typeDesc);
    }
    lower = initLower;
}

void ForStatement::print() {
    if(initLow){
        std::cout << "for " << name.getName() << " in Range(" << lower << ", " << upper;
        if(initIncrement){
            std::cout << ", " << increment;
        }
    }else {
        std::cout << "for " << name.getName() << " in Range(" << upper;
    }

    std::cout << "):" << std::endl;
    body->print();
}

bool ForStatement::range() {
    bool rng = lower < upper;   //check whether range should return true or false, and then lower is incremented
    if(initIncrement){
        lower += increment;
    }else{
        lower += 1;
    }
    return rng;
}

IfNode::IfNode() : relNode{nullptr}, body{nullptr}, evaluatedTrue{false} {}

IfNode::~IfNode() {
    delete relNode;
    delete body;
}

IfNode::IfNode(ExprNode *rel, Statements *bod) : relNode{rel}, body{bod}, evaluatedTrue{false} {}

void IfNode::print() {
    std::cout << "if ";
    relNode->print();
    std::cout << " :" << std::endl;
    body->print();
}

void IfNode::evaluate(SymTab &symTab) {
    if(dynamic_cast<NumberDescriptor*>(relNode->evaluate(symTab))->value.boolValue)
    {
        body->evaluate(symTab);
        evaluatedTrue = true;   //This tells ifStatement that this if statement was evaluated and it doesn't need to check any more else ifs or elses
    }
}

bool IfNode::evaluated() {
    bool eval = evaluatedTrue;
    evaluatedTrue = false;  //if the if statement is in a loop evaluatedTrue needs to be reset to false so that ifStatement will evaluate properly
    return eval;
}

IfStatement::IfStatement() : body{nullptr} {}

IfStatement::~IfStatement() {
    for(auto a : body){
        delete a;
    }
}

IfStatement::IfStatement(std::vector<IfNode *> ifs) : body{ifs} {}

void IfStatement::print() {
    for(unsigned i = 0; i < body.size(); i++)
        body[i]->print();
}

void IfStatement::evaluate(SymTab &symTab) {
    for(unsigned i = 0; i < body.size(); i++){
        body[i]->evaluate(symTab);
        if(body[i]->evaluated())
            break;  //if we evaluated a ifNode break out of the loop
    }
}

/*  The majority of the work is done by the class 'convert'.
    This class builds an expression tree using the input infix
    expression.  A post-order traversal of the expression tree 'dumps'
    it into an array in postfix form.  The iterator copies the token
    from this array to user's arrays.

*/

#include<vector>
#include<iostream>

#include "Token.hpp"
#include "Parser.hpp"
#include "Statements.hpp"

// Parser functions

void Parser::die(std::string where, std::string message, Token &token) {
    std::cout << where << " " << message << std::endl;
    token.print();
    std::cout << std::endl;
    std::cout << "\nThe following is a list of tokens that have been identified up to this point.\n";
    tokenizer.printProcessedTokens();
    exit(1);
}

Statements *Parser::statements() {
    // This function is called when we KNOW that we are about to parse
    // a series of assignment statements.
    //modified to include relational statements


    Statements *stmts = new Statements();
    Token tok = tokenizer.getToken();
    int indentLevel;    //this is used to see where the statements indent level is, the first one should be 0
    if(tok.isIndent())
    {
        indentLevel = tok.getIndent();
        tok = tokenizer.getToken();
    }
    else
    {
        indentLevel = 0;
    }
    while (tok.isName() || tok.eol()) {
        while(tok.eol()){
            tok = tokenizer.getToken();
        }
        //if we receive a dedent token that is at the correct level then we break out of the loop
        if(tok.isDedent()){
            if(tok.getDedent() != indentLevel)
            {
                die("Dedent", "incorrect dedent", tok);
            }
            break;

        }
        if(tok.isPrint())
        {
            tok = tokenizer.getToken();
            //keep grabbing tokens and put them in a vector until we find either a eol or eof token
            std::vector<Token> mess;
            while(!tok.eol() && !tok.eof()){
                mess.push_back(tok);
                tok = tokenizer.getToken();
            }
            PrintStatement *printStmt = new PrintStatement(mess);
            stmts->addStatement(printStmt);

        }
        else if(tok.isFor()){
            int loopIndent;
            int lower, upper, increment;
            bool initLower = false, initIncrement = false;
            Token id = tokenizer.getToken();

            if(!id.isName())
                die("Parser::forStatement", "Expected a name, instead got", tok);

            tok = tokenizer.getToken();

            if(!tok.isIn())
                die("Parser::forStatement", "Expected a in, instead got", tok);

            tok = tokenizer.getToken();

            if(!tok.isRange())
                die("Parser::forStatement", "Expected range, instead got", tok);

            tok = tokenizer.getToken();

            if(!tok.isOpenParen())
                die("Parser::forStatement", "Expected a open parenthesis, instead got", tok);
            tok = tokenizer.getToken();

            if(!tok.isWholeNumber())
                die("Parser::forStatement", "Expected a whole number, instead got", tok);

            upper = tok.getWholeNumber();

            tok = tokenizer.getToken();
            //for range we are seeing how many integers were used
            if(tok.isComma()){
                tok = tokenizer.getToken();
                if(!tok.isWholeNumber())
                    die("Parser::forStatement", "Expected a whole number, instead got", tok);
                lower = upper;
                upper = tok.getWholeNumber();
                initLower = true;

                tok = tokenizer.getToken();
                if(tok.isComma()){
                    tok = tokenizer.getToken();
                    if(!tok.isWholeNumber())
                        die("Parser::forStatement", "Expected a whole number, instead got", tok);
                    increment = tok.getWholeNumber();
                    initIncrement = true;

                    tok = tokenizer.getToken();
                    if(!tok.isCloseParen())
                        die("Parser::forStatement", "Expected a close parenthesis, instead got", tok);
                }
                else if(!tok.isCloseParen()){
                    die("Parser::forStatement", "Expected a close parenthesis, instead got", tok);
                }
            }
            else if(!tok.isCloseParen()){
                die("Parser::forStatement", "Expected a close parenthesis, instead got", tok);
            }

            tok = tokenizer.getToken();
            if(!tok.isColon()){
                die("Parser::forStatement", "Expected a :, instead got", tok);
            }
            Statements *bod = body();   //body is a function that checks indent and dedent tokens, and returns statements

            ForStatement *forStatement;
            //check which constructor to use in my for statement
            if(initLower) {
                if(initIncrement) {
                    forStatement = new ForStatement(id, lower, upper, increment, bod);
                }
                else{
                    forStatement = new ForStatement(id, lower, upper, bod);
                }
            } else{
                forStatement = new ForStatement(id, upper, bod);
            }
            stmts->addStatement(forStatement);
        }
        else if(tok.isIf()){
            std::vector<IfNode*> ifs;
            ExprNode *rel;
            do {
                if(tok.isElse()) {
                    tok = tokenizer.getToken();
                    if (!tok.isIf()) {
                        tokenizer.ungetToken();
                        rel = returnTrue(); //this is not an else if and should always execute if we get to it
                    }
                    else{
                        rel = test();
                    }
                }
                else{
                    rel = test();
                }

                Statements *bod = body();

                IfNode *node = new IfNode(rel, bod);
                ifs.push_back(node);
                tok = tokenizer.getToken();

            }while(tok.isElse());
            IfStatement *ifStmt = new IfStatement(ifs);
            stmts->addStatement(ifStmt);
            tokenizer.ungetToken();
        }
        else {
            tokenizer.ungetToken();
            AssignmentStatement *assignStmt = assignStatement();
            stmts->addStatement(assignStmt);
        }
        tok = tokenizer.getToken();

    }


    tokenizer.ungetToken();

    return stmts;
}

//body checks for an indent, creates a new set of statements at that indent level, and checks the dedent token
Statements *Parser::body() {
    Token tok;
    tok = tokenizer.getToken();
    if(!tok.eol()){
        die("Parser::body", "Expected a eol, instead got", tok);
    }
    while (tok.eol()) {
        tok = tokenizer.getToken();
    }
    if (!tok.isIndent()) {
        die("Parser::body", "Expected a indent, instead got", tok);
    }
    int ifLevel = tok.getIndent();

    tokenizer.ungetToken();
    Statements *bod = statements();
    tok = tokenizer.getToken();
    if (!tok.isDedent())
        die("Parser::body", "Expected a dedent, instead got", tok);
    if (tok.getDedent() != ifLevel) {
        std::cout << "Dedent is " << tok.getDedent() << std::endl;
        die("Parser::body", "incorrect indent level, expected " + std::to_string(ifLevel) + " got ",
            tok);
    }
    return bod;
}

//creates a token that represents a true value and checks if the next token is a colon
ExprNode *Parser::returnTrue(){
    Token tok;
    tok.setWholeNumber(1);
    tok = tokenizer.getToken();
    if(!tok.isColon())
        die("Parser::returnTrue", "Expected a :, instead got", tok);
    return new WholeNumber(tok);
}


ExprNode *Parser::test() {
    //<test> -> <or_test>
    ExprNode *result = or_test();
    Token tok = tokenizer.getToken();
    if(!tok.isColon()){
        die("Parser::test", "Expected a :, instead got", tok);
    }
    return result;
}

ExprNode *Parser::or_test() {
    //<or_test> -> <and_test> {'or' <and_test>}
    ExprNode *left = and_test();
    Token tok = tokenizer.getToken();
    while(tok.isOr()){
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = and_test();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::and_test() {
    //<and_test> -> <not_test> {'and' <not_test>}
    ExprNode *left = not_test();
    Token tok = tokenizer.getToken();
    while(tok.isAnd()){
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = not_test();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::not_test(){
    //<not_test> -> 'not' <not_test> | <relTerm>

    Token tok = tokenizer.getToken();
    if(tok.isNot()){
        NotNode *p = new NotNode(tok);

        p->rel() = not_test();
        return p;
    }
    tokenizer.ungetToken();
    return relTerm();
}

ExprNode *Parser::relTerm() {
    //<relTerm> -> <expr> {(>, <, >=, <=) <expr>}
    ExprNode *left = expr();
    Token tok = tokenizer.getToken();
    //while(tok.isGreaterThanSign() || tok.isLessThanSign() || tok.isGreaterEqualThanSign() || tok.isLessThanEqualSign())
    while(tok.isRelational()){

        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = expr();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

AssignmentStatement *Parser::assignStatement() {
    Token varName = tokenizer.getToken();
    if (!varName.isName())
        die("Parser::assignStatement", "Expected a name token, instead got", varName);

    Token assignOp = tokenizer.getToken();
    if (!assignOp.isAssignmentOperator())
        die("Parser::assignStatement", "Expected an equal sign, instead got", assignOp);

    ExprNode *rightHandSideExpr = expr();

    Token tok = tokenizer.getToken();
    if (!tok.eol())
        die("Parser::assignStatement", "Expected a eol, instead got", tok);


    return new AssignmentStatement(varName.getName(), rightHandSideExpr);
}

ExprNode *Parser::expr() {
    // This function parses the grammar rules:

    // <expr> -> <term> { <add_op> <term> }
    // <add_op> -> + | -

    // However, it makes the <add_op> left associative.

    ExprNode *left = term();
    Token tok = tokenizer.getToken();
    while (tok.isAdditionOperator() || tok.isSubtractionOperator()) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = term();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}


ExprNode *Parser::term() {
    // This function parses the grammar rules:

    // <term> -> <primary> { <mult_op> <primary> }
    // <mult_op> -> * | / | %

    // However, the implementation makes the <mult-op> left associate.
    ExprNode *left = primary();
    Token tok = tokenizer.getToken();

    while (tok.isMultiplicationOperator() || tok.isDivisionOperator() || tok.isModuloOperator()) {
        InfixExprNode *p = new InfixExprNode(tok);
        p->left() = left;
        p->right() = primary();
        left = p;
        tok = tokenizer.getToken();
    }
    tokenizer.ungetToken();
    return left;
}

ExprNode *Parser::primary() {
    // This function parses the grammar rules:

    // <primary> -> [0-9]+
    // <primary> -> [_a-zA-Z]+
    // <primary> -> (<expr>)

    Token tok = tokenizer.getToken();
    if(tok.isSubtractionOperator()){
        tok = tokenizer.getToken();
        if(tok.isWholeNumber()){
            tok.setWholeNumber(-tok.getWholeNumber());
            return  new WholeNumber(tok);
        }
        else{
            die("Parser::primary", "Expected a WholeNumber, instead got", tok);
        }
    }
    if (tok.isWholeNumber() )
        return new WholeNumber(tok);
    else if( tok.isName() )
        return new Variable(tok);
    else if (tok.isOpenParen()) {
        ExprNode *p = expr();
        Token token = tokenizer.getToken();
        if (!token.isCloseParen())
            die("Parser::primary", "Expected close-parenthesis, instead got", token);
        return p;
    }
    else if(tok.isString()){
        return new StringNode(tok);
    }
    die("Parser::primary", "Unexpected token", tok);

    return nullptr;  // Will not reach this statement!
}

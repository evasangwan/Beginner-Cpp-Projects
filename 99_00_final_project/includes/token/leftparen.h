#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "token.h"
#include <iostream>
using namespace std;

class LeftParen : public Token{
    public:
    LeftParen(const string& t):lparen("("){
        
    }

    LeftParen(){
        lparen = "(";
    }

    virtual int getType()override{
        return 4;
    }

    virtual double getPrecedence() override{
        return 4;
    }

     string getLParen() const {
        return lparen;
    }
    
    private: 
    string lparen;
};

#endif
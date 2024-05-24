#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "token.h"
#include <iostream>
using namespace std;

class RightParen : public Token{
    public:
    RightParen(const string& t):rparen(")"){
        
    }

    RightParen(){
        rparen = ")";
    }

    virtual int getType()override{
        return 5;
    }

    virtual double getPrecedence() override{
        return 4;
    }

    string getRParen() const {
        return rparen;
    }
    
    private: 
    string rparen;
};

#endif
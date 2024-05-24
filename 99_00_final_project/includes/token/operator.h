#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include <iostream>
using namespace std;

class Operator : public Token{
    public:
    Operator(const string& t):_op(t){

    }

    virtual ostream& print(ostream& outs)const override{
        outs << "[" << _op << "]";
        return outs; 
    }

    string Op() const {
        return _op;
    }

    virtual int getType()override{
        return 2;
    }

    virtual double getPrecedence()override{
        if (_op == "+"){
            return 1;
        }

        if (_op == "-"){
            return 1;
        }

        if (_op == "*"){
            return 2;
        }

        if (_op == "/"){
            return 2;
        }

        if (_op == "^"){
            return 3;
        }

        if(_op == "@"){   //trig functions
            return 99;
        }

        if (_op == "$"){  //unary
            return 100;
        }

        return 0;
    }
   
    private:
    string _op;

};

#endif
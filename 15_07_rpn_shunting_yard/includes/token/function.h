#ifndef FUNCTION_H
#define FUNCTION_H
#include "token.h"
#include <iostream>
using namespace std;

class Function : public Token{
    public:
    Function(const string& t):func(t){
        
    }
    // string Func(){
    //     return func;
    // }
    virtual int getType()override{
        if (func == "X" || func == "x" || func == "sin" || func == "cos" || func == "tan"|| func == "cot"|| func == "sec"|| func == "csc" || func == "unary"){
            return 3;
        }
        return -1;
    }
    virtual double getVal() const{
        if (func == "sin"){
            return -1;
        }
        if (func == "cos"){
            return -2;
        }
        if (func == "tan"){
            return -3;
        }
        if (func == "cot"){
            return -4;
        }
        if (func == "sec"){
            return -5;
        }
        if (func == "csc"){
            return -6;
        }
        if (func == "unary"){
            return -7;
        }
        
        return 0;
    }
    virtual double getPrecedence(){
        return 5;
    }
    string getFunc() const {
        return func;
    }
     virtual ostream& print(ostream& outs)const override{
        outs << "[" << func << "]";
        return outs; 
    }
    private:
    string func;
};

#endif
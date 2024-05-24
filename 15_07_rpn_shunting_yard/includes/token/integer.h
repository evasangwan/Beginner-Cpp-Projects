#ifndef INTEGER_H
#define INTEGER_H
#include "token.h"
#include <iostream>
#include <string> 
using namespace std;

class Integer : public Token{
    public:
    Integer(const string& t):num(t){
        n = stod(num);
    }
    Integer(const double& t):n(t) {
        
    }

    virtual int getType() override{
        return 1;
    }

    virtual double getVal() const{
        return n;
    }
    virtual ostream& print(ostream& outs)const override{
        outs << "[" << n << "]";
        return outs; 
    }
    // friend ostream& operator<<(ostream& outs, const Integer& num) {
    // outs << num.getVal(); 
    // return outs;
    // }
    private:
    double n;
    string num;
};
#endif
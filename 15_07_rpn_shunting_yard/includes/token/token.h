#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

class Token{
    public:
    Token(const string& t): t_(t){
        cout << "or in here" << endl;
    }
    Token(double t):_t(t){
        cout << "here" << endl;
    }
    Token(){
        _t = 0;
    }
    // virtual int _Type(){
    //     return 0;
    // }
    virtual int getType(){
        return -1;
    }
    virtual double getVal() const{
        return _t;
    }
    virtual double getPrecedence(){
        return -1;
    }
    virtual ostream& print(ostream& outs) const{
        outs << "[" << t_ << "]";
        return outs; 
    }
    
    friend ostream& operator<<(ostream& outs, const Token& token) {
    return token.print(outs);
}
    private:
    double _t;
    string t_;
};

#endif
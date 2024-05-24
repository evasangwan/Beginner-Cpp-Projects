#include "rational.h"
#include <iostream> 
using namespace std;

    int Rational:: is_error() const{
        if (_d == 0){
            return 1;
        }
        return 0; 
    }

    Rational::Rational(){
        _n = 0; 
        _d = 1; 
        _error = is_error();
    }

    Rational::Rational(int num, int denom){
        set(num, denom);
    }
    Rational:: Rational(int w){
        _n = w; 
        _d = 1; 
        _error = is_error();
    }

    void Rational::set(int num, int denom){
            _n = num;
            _d = denom; 
            _error = is_error();
        }
    void Rational:: set_num(int n){
        _n = n;
        _error = is_error();
    }

    void Rational::set_denom(int d){
            _d = d;
            _error = is_error();
        }
  
    int Rational::get_num() const{
        return _n;
    }

    int Rational:: get_denom() const{
        return _d;
    }

    int Rational:: error() const{
        return _error;
    }

    string Rational:: error_description() const{
        if (_error == 1){
            return "Error: Denom is 0";
        }
        return "No Error!";
    } 
  
    void Rational:: reset(){
        _n = 0;
        _d = 1;
        _error = 0; 
    }

    Rational operator +(const Rational &num1, const Rational &num2){
    if (num1.is_error() || num2.is_error()){
        return Rational(0,0);
    }   
    int n; 
    int d; 
    n = num1.get_num() * num2.get_denom() + num2.get_num()*num1.get_denom();
    d = num1.get_denom() * num2.get_denom();
    return Rational(n,d);
    }

    Rational operator -(const Rational &num1, const Rational &num2){
    if (num1.is_error() || num2.is_error()){
        return Rational(0,0);
    }
    int n; 
    int d; 
    n = num1.get_num() * num2.get_denom() - num2.get_num()*num1.get_denom();
    d = num1.get_denom() * num2.get_denom();
    return Rational(n,d);
    }
    Rational operator *(const Rational &num1, const Rational &num2){
    if (num1.is_error() || num2.is_error()){
        return Rational(0,0);
    }
    int n; 
    int d; 
    n = num1.get_num()*num2.get_num();
    d = num1.get_denom()*num2.get_denom();
    return Rational(n,d);
    }
    Rational operator /(const Rational &num1, const Rational &num2){
    if (num1.is_error() || num2.is_error()){
        return Rational(0,0);
    }
    int n; 
    int d; 
    n = num1.get_num()*num2.get_denom();
    d = num1.get_denom()*num2.get_num();
    return Rational(n,d);
    }
    
    //will print UNDEFINED if num is in error.
    ostream& operator <<(ostream &outs, const Rational &num){
    if (num.is_error()){
        outs << "UNDEFINED";
    }
    else{
    outs << num.get_num() << "/" << num.get_denom();
    }
    return outs;

    }
    istream& operator >>(istream &ins, Rational &num){
    int n; 
    int d; 
    char slash; 
    ins >> n >> slash >> d; 
    if (d == 0){
        num.set(0,0);
    }
    else{
        num.set(n,d);
    }
    return ins;
    }





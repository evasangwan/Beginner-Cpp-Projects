#include "term.h"
#include <iostream> 
#include <iomanip>
using namespace std;

Term::Term(double coef, int exp){
    _coef = coef; 
    _exp = exp;
}

const double checking_val = 0.001;

bool operator==(const Term& lhs, const Term& rhs){
    if (lhs._exp == rhs._exp){
        if(abs(lhs._coef - rhs._coef) <= checking_val){
            return true;       //returns true if lhs is equal to rhs
        }
    }
    return false;
}
bool operator!=(const Term& lhs, const Term& rhs){
    if (lhs._exp != rhs._exp){
        if(abs(lhs._coef - rhs._coef) >= checking_val){
            return true;       //returns true if lhs is not equal to rhs
        }
    }
    return false;
} 

bool operator>(const Term& lhs, const Term& rhs){  
    if (lhs._exp > rhs._exp){
        return true;          //returns true if lhs is greater than rhs
    }
    return false;
}
bool operator<(const Term& lhs, const Term& rhs){
    if (lhs._exp < rhs._exp){
        return true;          //returns true if lhs is less than rhs
    }
    return false;
}

Term operator/(const Term& lhs, const Term& rhs){
    int new_exp = lhs._exp - rhs._exp;
    double new_coef = lhs._coef / rhs._coef; 
    return Term(new_coef, new_exp); 
}

ostream& operator<<(ostream& outs, const Term& t){
    if (t._coef >= 0){
        outs << " +";
    }
    outs << fixed << setprecision(1);
    outs << " " << t._coef << "X^" << t._exp; 
    return outs;
}

istream& operator>>(istream& ins, Term& t){
    double coeff; 
    char the_x;
    char upsidedownv; 
    int exponent;
    ins >> coeff >> the_x >> upsidedownv >> exponent;
    t = Term(coeff,exponent);
    return ins;
}
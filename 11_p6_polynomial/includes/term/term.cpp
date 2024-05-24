#include "term.h"
#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

Term::Term(double coef, int exp){
    _coef = coef; 
    _exp = exp;
}

const double checking_val = 0.00000001;

bool operator==(const Term& lhs, const Term& rhs){
    if (lhs._exp == rhs._exp){
        if(fabs(lhs._coef - rhs._coef) <= checking_val){
            return true;       //returns true if lhs is equal to rhs
        }
    }
    return false;
}
bool operator!=(const Term& lhs, const Term& rhs){
    if (lhs._exp != rhs._exp){
        if(fabs(lhs._coef - rhs._coef) >= checking_val){
            return true;       //returns true if lhs is not equal to rhs
        }
    }
    return false;
} 

bool operator>(const Term& lhs, const Term& rhs){  
    if (lhs._exp > rhs._exp){
        return true;          //returns true if lhs is greater than rhs
    }
    if (lhs._exp == rhs._exp){
        if(fabs(lhs._coef - rhs._coef) >= checking_val){
            if ((lhs._coef - rhs._coef) > checking_val){
                return true;
            }
        }
    }
    return false;
}
bool operator<(const Term& lhs, const Term& rhs){
        if (lhs._exp < rhs._exp){
            return true;          //returns true if lhs is greater than rhs
        }
        if (lhs._exp == rhs._exp){
            if(fabs(lhs._coef - rhs._coef) >= checking_val){
                if ((lhs._coef - rhs._coef) < checking_val){
                return true;
            }
        }
    }
    return false;
}

Term operator/(const Term& lhs, const Term& rhs){
    int new_exp = lhs._exp - rhs._exp;
    double new_coef = lhs._coef / rhs._coef; 
    return Term(new_coef, new_exp); 
}

ostream& operator<<(ostream& outs, const Term& t){
    outs << fixed << setprecision(1);
    if (t._exp != 0){
        if(t._coef == 0){
            return outs;
        }
    if (t._coef >= 0){
        outs << " +";
    }
    outs << " " << t._coef << "X^" << t._exp; 
    }
    else {
    if (t._coef >= 0){
        outs << " +";
    }
    outs << " " << t._coef;
    }
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
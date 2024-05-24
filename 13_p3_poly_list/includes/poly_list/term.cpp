#include <iostream> 
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_sorted/list_sorted.h"
#include <cassert>
#include "term.h"
#include <cmath> 
#include <iomanip>
using namespace std; 

Term::Term(){
    _coef = 0;
    _exp = 0; 
}

Term::Term(double coef, int order){
    _coef = coef;
    _exp = order;
}

Term& Term::operator +=(const Term &rhs){
    if (_exp == rhs._exp){
        _coef += rhs._coef;
    }
    return *this;
}
Term& Term::operator -=(const Term &rhs){
    if (_exp == rhs._exp){
        _coef -= rhs._coef;
    }
    return *this; 
}
Term& Term::operator *=(const Term &rhs){
    _exp += rhs._exp;
    _coef *= rhs._coef;
    return *this; 
}
Term& Term::operator /=(const Term &rhs){
    _exp -= rhs._exp;
    _coef /= rhs._coef;
    return *this;
}

bool operator ==(const Term &lhs, const Term &rhs){
        if (lhs._exp == rhs._exp){
            return true;
        }
        return false; 
    }
bool operator !=(const Term &lhs, const Term &rhs){
        if (lhs._exp != rhs._exp){
            return true;
        }
        return false; 
    }
bool operator >(const Term &lhs, const Term &rhs){
        if (lhs._exp > rhs._exp){
            return true;
        }
        return false; 
    }
bool operator <(const Term &lhs, const Term &rhs){
        if (lhs._exp < rhs._exp){
            return true;
        }
        return false; 
    }
Term operator +(const Term &lhs, const Term &rhs){
        if (lhs == rhs){
            double sum = lhs._coef + rhs._coef;
            return Term(sum, lhs._exp);
        }
        assert(true && "don't hv same exp");
        return Term(0,0);
    }
Term operator -(const Term &lhs, const Term &rhs){
        if (lhs == rhs){
            double difference = lhs._coef - rhs._coef; 
            return Term(difference, lhs._exp);
        }
        assert(true && "don't hv same exp");
        return Term(0,0);
    }
Term operator *(const Term &lhs, const Term &rhs){
        int new_exp = lhs._exp + rhs._exp;
        double product = lhs._coef * rhs._coef;
        return Term(product, new_exp);
    }
Term operator /(const Term &lhs, const Term &rhs){
        int new_exp = lhs._exp - rhs._exp;
        double quotient = lhs._coef / rhs._coef;
        return Term(quotient, new_exp);
    }

ostream& operator <<(ostream &outs, const Term &t){
        outs << fixed << setprecision(1);
        if (t._coef >= 0){
            outs << "+";
        }
        if (t._exp == 0){
            outs << t._coef << " ";
            return outs;
        }
        if (t._exp == 1){
            outs << t._coef << "X ";
            return outs;
        }
        outs << t._coef << "X^" << t._exp << " ";
        return outs; 
    }
istream& operator >>(istream &ins, Term &t){
        return ins;
    }

Term Term::operator -() const{
        return Term(_coef*-1, _exp);
    }

    bool double_equals(double left, double right){
    const double checking_val = 0.0001;
    if (fabs(left - right) <= checking_val){
        return true;
    }
    return false;
}
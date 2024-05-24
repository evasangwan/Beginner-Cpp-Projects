#include <iostream> 
#include "../../includes/list_sorted/list_sorted.h"
#include "poly.h"
#include "term.h"
#include <cassert>
#include <cmath> 
#include <iomanip>
#include <vector>
using namespace std; 

Poly:: Poly(){
    _order = 0; 
    _poly.insert(Term(0,0)); 
}

Poly::Poly(double *term_array, int order){
    _order = order;
    _poly.insert(Term(0,0)); 
    double *ptr = term_array;
    for (int i = 0; i < _order + 1; i++) {
        if(!double_equals(*ptr,0.0)){
             _poly.insert(Term(*ptr, i));
        }
        ptr++;
}
    List<Term>:: Iterator head = _poly.begin();
    _order = head->_exp;
}

Poly:: Poly(const vector<double>& terms){
    _order = terms.size() - 1;
    _poly.insert(Term(0,0)); 
    for (int i = 0; i < _order+1; i++){
        if(!double_equals(terms.at(i),0.0)){
            _poly.insert(Term(terms.at(i),i));
        }
    }
    List<Term>:: Iterator head = _poly.begin();
    _order = head->_exp;
}  

Poly:: Poly(const Poly& copyThis){
    _poly = copyThis._poly;
    _order = copyThis._order;
}

Poly& Poly:: operator =(const Poly& copyThis){
    if (&copyThis == this){
        return *this;
    }
    _poly = copyThis._poly;
    _order = copyThis._order;
    return *this; 
}

Poly:: ~Poly(){

}

Poly& Poly:: operator +=(const Term &t){
    _poly.insert(t);
    if (_order < t._exp){
        _order = t._exp;
    }
    Poly res(*this);
    List<Term>::Iterator to_delete = res._poly.begin();
    while(!to_delete.is_null()){
        if((double_equals(to_delete->_coef, 0.0) && to_delete->_exp > 0)){
            res._poly.Delete(to_delete);
        }
        to_delete++;
    }
    List<Term>::Iterator head = res._poly.begin();
    res._order = head->_exp;
    // // cout << "res order before deleting "<< res._order << endl;
    // List<Term>::Iterator to_delete = res._poly.begin();
    // cout << "res " << res << endl;
    // while(!to_delete.is_null()){
    //     cout << "to_delete->_coef " << to_delete->_coef << endl;
    //     cout << "to_delete->_exp  " << to_delete->_exp << endl;
    //     if((double_equals(to_delete->_coef, 0.0) && to_delete->_exp > 0)){
    //          if(to_delete->_exp == _order){
    //                 _order--;
    //         }
    //         res._poly.Delete(to_delete);
    // }
    //     to_delete++;
    // }
    // // cout << "res order after deleting " << res._order << endl;
    *this = res;
    return *this;
}

Poly& Poly:: operator *=(const Term &t){
    Poly product(*this);
    List<Term>::Iterator walker = product._poly.begin();
    while(!(walker.is_null())){
        *walker *= t;
        // if (walker->_exp > _order){
        //     _order = walker->_exp;
        // }
        walker++;
    }
    *this = product;
    return *this; 
}

Poly& Poly:: operator +=(const Poly &RHS){
    List<Term>::Iterator walker = RHS._poly.begin();
    while(!walker.is_null()){
        *this += *walker;   //*this is the current Poly. adding poly+=term
    //  if (walker->_exp > _order) {
    //     _order = walker->_exp;
    // }
        walker++;
    // cout << "adding " << *this << "w this" << *walker << endl;
    }
    return *this;
}

Poly& Poly::operator *=(const Poly &RHS) {
    Poly product;
    List<Term>::Iterator rhs = RHS._poly.begin();
    while (!rhs.is_null()) {
        Poly mul = *this * *rhs;  
        product += mul; 
        // if (mul._order > _order) {
        //     _order = mul._order;
        // } 
        rhs++;
    }
    *this = product;  
    return *this;
}

Poly& Poly:: operator -=(const Poly &RHS){
    // *this = *this + -(RHS);
    // return *this;
    Poly diff(*this);
    diff = diff + -(RHS);
    // // if (diff._order > _order){
    // //     _order = diff._order;
    // // }
    // // List<Term>::Iterator to_delete = diff._poly.begin();
    // // if(double_equals(to_delete->_coef, 0.0)){
    // //     if (!to_delete.is_null()) {
    // //         diff._poly.Delete(to_delete);
    // //         diff._order--;  //added this 
    // //         }
    // //     }
    *this = diff;
    return *this;
}

bool operator ==(const Poly &left, const Poly &right){
    if (left._order == right._order){
        List<Term>::Iterator lhs = left._poly.begin();
        List<Term>::Iterator rhs = right._poly.begin();
        if(double_equals(lhs->_coef, rhs->_coef)){
            return true;
        }
    }
    return false; 
}

bool operator !=(const Poly &left, const Poly &right){
    if (left._order == right._order){
        List<Term>::Iterator lhs = left._poly.begin();
        List<Term>::Iterator rhs = right._poly.begin();
        if(double_equals(lhs->_coef, rhs->_coef)){
            return false;
        }
    }
    return true; 
}

Poly operator +(const Poly &left, const Poly &right){
       Poly sum(left);
       sum += right;
       return sum;
    }

Poly operator -(const Poly &left, const Poly &right){
        Poly diff(left);
        diff -= right;
        return diff;
    }

Poly operator *(const Poly &left, const Poly &right){
        Poly product(left);
        product *= right;
        return product;
    }

Poly operator /(const Poly &left, const Poly &right) {
    if (right._order > left._order) {
        return Poly();
    }
    if (right._order == 0 && right._poly.begin() == 0){
        return left;
    }
    Poly result;
    Poly temp_l = left;
    while (temp_l._order >= right._order) {
        int l = temp_l._order;
        int r = right._order;
        Term res = temp_l[l] / right[r];
        result += res;
        Poly sub = right*res;
        temp_l -= sub;
        if (temp_l._order == l) {  //if orders r the same, then that means nothing left to divide so do -- so loop breaks 
            temp_l._order--;
        }
    }
    return result;
    // return left;
}

Poly operator %(const Poly &left, const Poly &right){
    Poly div = left / right;
    return left - div * right;
    // return left;
}

Poly Poly:: operator -() const{
    Poly result(*this);
    // Term t = result[result._order]
    List<Term>::Iterator walker = result._poly.begin();
    while(!walker.is_null()){
        walker->_coef *= -1;
        walker++;
    }
    return result;
}

Poly operator +(const Poly &left, const Term &t){
    Poly temp(left);
    temp += t;
    return temp;
}

Poly operator *(const Poly &left, const Term &t){
    Poly temp(left);
    temp *= t;
    return temp;
}

ostream& operator <<(ostream &outs, const Poly &print_me){
    List<Term>::Iterator temp = print_me._poly.begin();
    while(!(temp.is_null())){
        outs << *temp;
        temp++;
    }
    outs << "["<<print_me._order<< "]";
    return outs; 
}

istream& operator >> (istream& ins, Poly& read_me){
    return ins;
}

const Term t(0,0);    
const Term& Poly:: operator [](const int exp) const{
    List<Term>:: Iterator walker = _poly.begin();
    while (walker != nullptr){
        if (walker->_exp == exp){
            return *walker;
        }
        walker++;
    }
    assert(true && "term not found");
    // const Term t(0,0);
    return t;
}

Term r(0,0);
Term& Poly:: operator [] (const int exp){
    List<Term>:: Iterator walker = _poly.begin();
    while (walker != nullptr){
        if (walker->_exp == exp){
            return *walker;
        }
        walker++;
    }
    assert(true && "term not found");
    return r;
}
    
List<Term> Poly::list() const{
    return _poly;
}












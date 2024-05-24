#ifndef POLY_H
#define POLY_H
#include <iostream> 
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/term/term.h"
using namespace std; 

class Poly{
public: 
    Poly(){
        _order = 0;
        _coefs = nullptr;
    }

    Poly(double* coefs, int order){
        _order = order;
        _coefs = copy_array(coefs, _order+1);
    }

    //big 3
    Poly(const Poly& other){
        _order = other._order;
        _coefs = allocate<double>(_order + 1);
        copy_array(_coefs, other._coefs, _order +1);
        // fix_order();
    }

    Poly& operator=(const Poly& rhs){
        if(&rhs == this){
            return *this;
        }
        delete [] _coefs;
        _order = rhs._order;
        _coefs = allocate<double>(_order + 1);
        copy_array(_coefs, rhs._coefs, _order +1);
        //  fix_order();
        return *this;
    }

    ~Poly(){
        delete[] _coefs;
        _coefs = nullptr;
    }

    friend bool operator ==(const Poly& lhs, const Poly& rhs){
        if (lhs._order != rhs._order){
            return false;
        }
        for (int i = 0; i <= lhs._order; i++){
            if (lhs[i] != rhs[i]){
                return false;
            }
        }
        return true;
    }

    friend bool operator !=(const Poly& lhs, const Poly& rhs){
        if (lhs._order != rhs._order){
            return true;
        }
        for (int i = 0; i < lhs._order; i++){
            if (lhs[i] != rhs[i]){
                return true;
            }
        }
        return false;
    }

    friend bool operator >(const Poly& lhs, const Poly& rhs){
        return true;
    }

    friend bool operator <(const Poly& lhs, const Poly& rhs){
        return true;
    }

    Term operator[](int order) const{
        double *ptr = _coefs;
        ptr += order;
        return Term(*ptr, order);
    }

    friend Poly operator +(const Poly& lhs, const Term& t){
        Poly result; 
        if(t._exp <= lhs._order){
            result = lhs;
        }
        if(t._exp > lhs._order){
            result._order = t._exp;
            int size = result._order + 1;
            int capacity = size;
            result._coefs = allocate<double>(capacity);
            double *p = result._coefs;
            for (int i = 0; i < size; i++){
                *p = 0.0;
                p++;
            }
            copy_array(result._coefs, lhs._coefs, lhs._order+1);
        }
        double *ptr = result._coefs;
        ptr += t._exp;
        *ptr += t._coef;
        result.fix_order();
        return result;
    }

    friend Poly operator +(const Poly& lhs, const Poly& rhs){
        Poly result;
        result = lhs;
        int order;
        if (lhs._order >= rhs._order){
            order = lhs._order;
        }
        if (rhs._order > lhs._order){
            order = rhs._order;
            result._coefs = allocate<double>(rhs._order+1);
            double *p = result._coefs;
             for (int i = 0; i < rhs._order+1; i++){
                *p = 0.0;
                p++;
            }
            copy_array(result._coefs, lhs._coefs, lhs._order+1);
        }
        result._order = order;
        for (int i = rhs._order; i >= 0; i--){
            Term right = rhs[i];
            result = result + right;
        }
        // cout << "result._order " << result._order << endl;
        result.fix_order();
        return result;
    }

    friend Poly operator -(const Poly& p){
        Poly result; 
        result = p;
        double *ptr = result._coefs;
        ptr += result._order; 
        for (int i = result._order; i >= 0; i--){
            *ptr *= -1;
            ptr--;
        }
        result.fix_order();
        return result; 
    }

    friend Poly operator -(const Poly& lhs, const Poly& rhs){ 
        Poly result = lhs + (-rhs);
        result.fix_order();
        return result;
    }

    friend Poly operator *(const Poly& lhs, const Term& t){
        Poly result;
        int order = lhs._order + t._exp;
        result._order = order;
        int size = result._order + 1;
        int capacity = size;
        result._coefs = allocate<double>(capacity);
        double *ptr = result._coefs;
        for (int i = 0; i < size; i++){
            *ptr = 0.0;
            ptr++;
        }
        ptr -= size;
        for (int i = lhs._order; i >= 0; i--){
            Term left = lhs[i];
            ptr += (left._exp + t._exp);
            *ptr = (left._coef * t._coef);
            ptr -= (left._exp + t._exp);
        }
        result.fix_order();
        return result; 
        //return lhs;
    }

    friend Poly operator *(const Poly& lhs, const Poly& rhs){
        Poly result; 
        result._order = lhs._order + rhs._order;
        int size = result._order + 1;
        int capacity = size;
        result._coefs = allocate<double>(capacity);
        double *ptr = result._coefs;
        for (int i = 0; i < size; i++){
            *ptr = 0;
            ptr++;
        }
        ptr -= size;   
        for (int i = rhs._order; i >= 0; i--){
            Term right = rhs[i];
            Poly product = (lhs * right);
            result = result + product;
        }
        result.fix_order();
        return result;
        //return lhs;
    }

    friend Poly operator /(const Poly& lhs, const Poly& rhs){
        // Poly result; 
        // int capacity = 100;
        // result._coefs = allocate<double>(capacity);
        // for (int i = lhs._order; i >= 0; i--){
        // Term left = lhs[i];
        // }
        return lhs;
    }

    friend Poly operator %(const Poly& lhs, const Poly& rhs){
        return lhs;
    }

    friend ostream& operator<<(ostream& outs, const Poly& p){ 
        double *ptr = p._coefs + p._order;
        int order = p._order;
        for (int i = p._order; i >= 0; i--){
            Term t(*ptr,order);
            outs << t;
            ptr--;
            order--;
        }
        return outs;
    }

    friend istream& operator>>(istream& ins, Poly& p){
        int ord = p._order;
        p = Poly(0,ord);
        for (int i = p._order; i >= 0; i--){
            Term t(0,0);
            ins >> t; 
            p = p + t;
        }
        return ins;
    }

    double* get_coefs() const{
        return _coefs;
    }

    int order() const {return _order;};

    // void set_order(int new order); apparently we don't use it 

    void fix_order(){
        int new_order = _order; 
        double *ptr = _coefs; 
        ptr += new_order;
        while ((*ptr == 0.0)&&(new_order > 0)){
            new_order--;
            ptr--;
        }
        _order = new_order;
    }

private:
    int _order;
    double* _coefs;
};


#endif // POLY_H
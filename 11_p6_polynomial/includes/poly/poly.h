#ifndef POLY_H
#define POLY_H
#include <iostream> 
#include <cmath>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/term/term.h"
using namespace std; 

// Poly::Poly(double *term_array, int order){
//     _order = order;
//     _poly.insert(Term(0,0)); 
//     double *ptr = term_array;
//     for (int i = 0; i < _order + 1; i++) {
//         if((double_equals(*ptr, 0.0)&& i > 0)){
//             List<Term>::Iterator to_delete = _poly.search(Term(*ptr, i));
//             if (!to_delete.is_null()){
//                 if(to_delete->_exp == _order){
//                     _order--;
//                 }
//                 _poly.Delete(to_delete);
//             }
//         }
//         else{
//             _poly.insert(Term(*ptr, i));
//         }
//         ptr++;
//     }
// }

// Poly:: Poly(const vector<double>& terms){
//     _order = terms.size() - 1;
//     _poly.insert(Term(0,0)); 
//     for (int i = 0; i < _order+1; i++){
//         if((double_equals(terms.at(i), 0.0) && i > 0)){
//         List<Term>::Iterator to_delete = _poly.search(Term(terms.at(i),i));
//         if (!to_delete.is_null()) {
//             if(to_delete->_exp == _order){
//                     _order--;
//                 }
//             _poly.Delete(to_delete);
//         }
//     }
//     else{
//         _poly.insert(Term(terms.at(i),i));
//     }
//     }   
// }
class Poly{
public: 
    Poly(){
        _order = 0;
        _coefs = allocate<double>(_order+1);
        double *ptr = _coefs;
        for (int i = 0; i < _order+1; i++){
            *ptr = 0;
            ptr++;
        }
    }

    Poly(double* coefs, int order){
        _order = order;
        _coefs = allocate<double>(_order + 1);
        double *ptr = _coefs;
        for (int i = 0; i < _order+1; i++){
            *ptr = 0.0;
            ptr++;
        }
        copy_array(_coefs, coefs, _order +1);
        fix_order();
        // _coefs = copy_array(coefs, _order + 1);  //maybe do it
    }

    //big 3
    Poly(const Poly& other){
        _order = other._order;
        _coefs = allocate<double>(_order + 1);
        double *ptr = _coefs;
        for (int i = 0; i < _order+1; i++){
            *ptr = 0.0;
            ptr++;
        }
        copy_array(_coefs, other._coefs, _order +1);
        fix_order();
    }

    Poly& operator=(const Poly& rhs){
        if(&rhs == this){
            return *this;
        }
        delete [] _coefs;
        _order = rhs._order;
        _coefs = allocate<double>(_order + 1);
        double *ptr = _coefs;
        for (int i = 0; i < _order+1; i++){
            *ptr = 0.0;
            ptr++;
        }
        copy_array(_coefs, rhs._coefs, _order +1);
        //fix_order(); //comment this out 
        return *this;
    }

    ~Poly(){
        delete[] _coefs;
        _coefs = nullptr;
    }

    friend bool operator ==(const Poly& lhs, const Poly& rhs){
        if (lhs._order != rhs._order){
            return false;
        }                                                //compare highest coeffs not all of them!
        double *lhs_ptr = lhs._coefs; 
        double *rhs_ptr = rhs._coefs;
        lhs_ptr+= lhs._order;
        rhs_ptr+= rhs._order;
        if (*lhs_ptr != *rhs_ptr){
            return false;
        }
        return true;
    }

    friend bool operator !=(const Poly& lhs, const Poly& rhs){
       if (lhs._order == rhs._order){
            return false;
        }                                                
        double *lhs_ptr = lhs._coefs; 
        double *rhs_ptr = rhs._coefs;
        lhs_ptr+= lhs._order;
        rhs_ptr+= rhs._order;
        if (*lhs_ptr == *rhs_ptr){
            return false;
        }
        return true;
    }

    friend bool operator >(const Poly& lhs, const Poly& rhs){
        if (lhs._order > rhs._order){
            return true;
        }                                               
        double *lhs_ptr = lhs._coefs; 
        double *rhs_ptr = rhs._coefs;
        lhs_ptr+= lhs._order;
        rhs_ptr+= rhs._order;
        if (*lhs_ptr < *rhs_ptr){
            return false;
        }
        return false;
    }

    friend bool operator <(const Poly& lhs, const Poly& rhs){
        if (lhs._order < rhs._order){
            return true;
        }                                                
        return false;
    }

    Term operator[](int order) const{
        double *ptr = _coefs;
        ptr += order;
        return Term(*ptr, order);
    }

    friend Poly operator +(const Poly& lhs, const Term& t){
        //cout << "lhs " << lhs << endl;
        Poly result; 
        // int order = 0;
        //cout << "result in the beginning " << result << endl;
        if(t._exp <= lhs._order){
            result = lhs;
            //cout << "result = lhs " << result << endl;
        }
        if(t._exp > lhs._order){
            // order = t._exp;
            result._order = t._exp;
            int size = result._order + 1;
            //cout << "size is " << size << endl;
            int capacity = size;
            result._coefs = allocate<double>(capacity);
            double *p = result._coefs;
            for (int i = 0; i < size; i++){
                *p = 0.0;
                p++;
            }
            copy_array(result._coefs, lhs._coefs, lhs._order+1);
            //cout << "after copuing " << result << endl;
        }
        double *ptr = result._coefs;
        //cout << "result order " << result._order << endl;
        ptr += t._exp;
        *ptr += t._coef;
        //cout << "*ptr = " << *ptr << endl;
        //cout << "result before fix order  " << result << endl;
        result.fix_order();
        //cout << "result after fix order " << result << endl;
        return result;
    }

    friend Poly operator +(const Poly& lhs, const Poly& rhs){
        // const bool debug = false;
        Poly result;
        result = lhs;
        // int order;
        // if (lhs._order >= rhs._order){
        //     order = lhs._order;
        // }
        // if (rhs._order > lhs._order){
        //     order = rhs._order;
        //     result._coefs = allocate<double>(rhs._order+1);
        //     double *p = result._coefs;
        //      for (int i = 0; i < rhs._order+1; i++){
        //         *p = 0.0;
        //         p++;
        //     }
        //     copy_array(result._coefs, lhs._coefs, lhs._order+1);
        // }
        // result._order = order;
        
        for (int i = rhs._order; i >= 0; i--){
            Term right = rhs[i];
            result = result + right;        
            // if (debug)
            //     cout << "result " << result << endl;
            //cout << "result._order is " << result._order << endl;
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

    //poly*poly(0) poly(0)*poly 

    //poly(0) * poly poly-poly (same poly)  divide by itself p/p

    friend Poly operator -(const Poly& lhs, const Poly& rhs){ 
        Poly result = lhs + (-rhs);
        result.fix_order();
        return result;
    }

    friend Poly operator *(const Poly& lhs, const Term& t){
        Poly result;
       // cout << "result then " << result << endl;
        int order = lhs._order + t._exp;
        result._order = order;
        int size = result._order + 1;
        int capacity = size;
        result._coefs = allocate<double>(capacity);
        double *ptr = result._coefs;
        for (int i = 0; i < size; i++){
            *ptr = 0;
            ptr++;
        }
        //cout << "result now " << result << endl;
        ptr = result._coefs;
        for (int i = lhs._order; i >= 0; i--){
            Term left = lhs[i];
            ptr += (left._exp + t._exp);
            *ptr = (left._coef * t._coef);
            ptr -= (left._exp + t._exp);
        }
        //cout << "result////////// " << result << endl;
        // result.fix_order();
        return result; 
        //return lhs;
    }

    friend Poly operator *(const Poly& lhs, const Poly& rhs){
        if ((lhs._order == 0)&&(*lhs._coefs == 0)){
            Poly c;
            return c;
        }
        if ((rhs._order == 0)&&(*rhs._coefs == 0)){
            Poly c;
            return c;
        }
        Poly result; 
        //thisssssssssssssssssssssssssssssss
        // result._order = lhs._order + rhs._order;
        // result._coefs = allocate<double>(result._order+1);
        // double *ptr = result._coefs; 
        // for (int i = 0; i < result._order+1; i++){
        //     *ptr = 0;
        //     ptr++;
        // }
        for (int i = rhs._order; i >= 0; i--){
            Term right = rhs[i];
            // cout << "right " << right << endl;
            Poly product = lhs * right;
            result = result + product;
            //cout << result << endl;
        }
    result.fix_order();
    return result;
    }

    friend Poly operator /(const Poly& lhs, const Poly& rhs){
        if (lhs < rhs){
            Poly p; 
            return p;
        }
        int order = lhs._order - rhs._order;
        if (order < 0) {
            Poly p;
            return p;
        }
        if ((*rhs._coefs == 0)&&(rhs._order == 0)){
            Poly p;
            return p;
        }
        if (rhs._order == 0){
            Poly result;
            result._order = lhs._order;
            result._coefs = allocate<double>(result._order + 1);
            // double *p = result._coefs;
            // *p = 0;
            double *ptr = result._coefs;
            for (int a = 0; a < result._order + 1; a++){
                *ptr = 0;
                ptr++;
        }
        //cout << "result._order " << result._order << endl;
        for (int i = result._order; i >= 0; i--){
            Term res = lhs[i] / rhs[0];
            //cout << "res " << res << endl;
            //cout << "result before " << result << endl;
            //cout << result << " = " << result << " + " << res << endl;
            result = result + res;
            //cout << "result " << result << endl;
        }
        result.fix_order();
        return result;
        }
        Poly result; 
        result._order = lhs._order - rhs._order;
        int size = result._order + 1;
        result._coefs = allocate<double>(size);
        // double *p = result._coefs;
        // *p = 0;
        double *ptr = result._coefs;
        for (int a = 0; a < size; a++){
            *ptr = 0;
            ptr++;
        }
        int l = lhs._order;
        int r = rhs._order;
        Poly temp_l = lhs;
        while (l >= r){
            Term res = temp_l[l]/rhs[r];
             result = result + res;
            Poly sub = result * rhs;
            Poly new_lhs = lhs - sub;
            temp_l = new_lhs;
            temp_l.fix_order();
            l = temp_l._order;  
            if (l < r ){
                break;
            }
            }
        result.fix_order();
        return result;
        //return lhs;
    }

    friend Poly operator %(const Poly& lhs, const Poly& rhs){
         Poly div = lhs / rhs;
         return lhs - div * rhs;
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
        const double checking_val = 0.00000001;
        int new_order = _order; 
        double *ptr = _coefs; 
        ptr += new_order;
        //cout << "Fixorder ptr Value= " << *ptr << endl;
        //fabs(lhs._coef - rhs._coef) <= checking_val)
        while ((fabs(*ptr - 0)<= checking_val)&&(new_order > 0)){
            new_order--;
            ptr--;
        }
        _order = new_order;
        // cout << "ORDER IS NOW " << _order << endl;
    }

private:
    int _order;
    double* _coefs;
};


#endif // POLY_H
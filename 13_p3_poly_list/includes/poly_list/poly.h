#ifndef POLY_H
#define POLY_H
#include <iostream> 
#include <vector>
#include "term.h"
#include "../../includes/list_sorted/list_sorted.h"
using namespace std; 

class Poly{
    public: 
        Poly();
        Poly(double *term_array, int order);
        Poly(const vector<double>& terms);
        
        //these are my big 3?
        Poly(const Poly& copyThis);
        Poly& operator =(const Poly& copyThis);
        ~Poly();
        //

        Poly& operator +=(const Term &t);
        Poly& operator *=(const Term &t);
        Poly& operator +=(const Poly &RHS);
        Poly& operator *=(const Poly &RHS);
        Poly& operator -=(const Poly &RHS);

        friend bool operator ==(const Poly &left, const Poly &right);
        friend bool operator !=(const Poly &left, const Poly &right);
        friend Poly operator +(const Poly &left, const Poly &right);
        friend Poly operator -(const Poly &left, const Poly &right);
        friend Poly operator *(const Poly &left, const Poly &right);
        friend Poly operator /(const Poly &left, const Poly &right);
        friend Poly operator %(const Poly &left, const Poly &right);
        Poly operator -() const;

        friend Poly operator +(const Poly &left, const Term &t);
        friend Poly operator *(const Poly &left, const Term &t);
        friend ostream& operator <<(ostream &outs, const Poly &print_me);
        friend istream& operator >> (istream& ins, Poly& read_me);
        //  if (temp.is_null()){
        //         temp_poly._poly.Delete(temp);
        //     }
        
        const Term& operator [](const int exp) const;
        Term& operator [] (const int exp);
        List<Term> list() const;

    private:
        List<Term> _poly;
        int _order;
};

#endif
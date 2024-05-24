#include <iostream>
#include <iomanip>
#include "includes/rational/rational.h"
using namespace std;

void display_results(Rational& r1, Rational& r2){
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
}

void test_rational(){
    bool done = false;
    char choice;
    cout << "[A] [B]   e[X]it" << endl;
    Rational a(1,4);
    Rational b(2,9);
    display_results(a,b);
    do {
        cout << ": "; 
        cin >> choice;

        switch(toupper(choice)){
            case 'A':
                cout << "A: "; 
                int num; 
                int denom;
                char slash;
                cin >> num >> slash >> denom; 
                a.set(num, denom);
                display_results(a,b);
                break;
            case 'B':
                cout << "B: "; 
                int num2; 
                int denom2;
                 char slash2;
                cin >> num2 >> slash2 >> denom2; 
                b.set(num2, denom2);
                display_results(a,b);
                break;
            case 'X':
                done = true;
                break;
        }

    } while (!done);
}

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    test_rational();
    
    
    cout << "\n\n\n=====================" << endl;
    return 0;
}


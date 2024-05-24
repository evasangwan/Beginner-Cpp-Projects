#include <iostream>
#include <iomanip>
#include "includes/counter_type/counter_type.h"

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    Counter_Type c; 
    char choice;
    bool done = false;
    cout << "[+]  [-]   [r]        E[x]it" << endl;
    do
    {
        bool error_code = c.is_error();
        if (!c.is_error())
        {
            c.print();
        }

        cout << "-------- " << c.count() << "------" << endl;
        cout << ":";
        cin >> choice;

        switch (toupper(choice))
        {
        case '+':
        case '=':
            c.inc();
            break;
            case '_': 
            case '-': c.dec();
            break;
            case 'C': 
            case 'R' : 
            case 27 : c.reset();
            break;
            case 'X' : done = true;
            break;
            }

    } while (!done);

    cout
        << "\n=====================" << endl;
    return 0;
}


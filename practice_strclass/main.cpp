#include <iostream>
#include <iomanip>
#include <cstring> 
#include <string> 
#include "includes/string/string.h"

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
    << endl;
    String s;
    cout << "Enter a str: ";
    cin >> s; 
    cout << endl;
    cout << s << endl;
    cout << "length " << s.length() << " " << endl;
    s.upper();
    cout << s << endl;
    s.lower();
    cout << s << endl;
    // char ch = 'x';
    // cout << ch << endl;
    s.push_back('a'); 
    cout << s << endl;
    cout << "length " << s.length() << " " << endl;
    // s.pushback("abc"); 
    // cout << s << endl;
    //cout << "proving papa wrong" << endl;
    String s1; 
    s1 = s;
    s.upper();
    cout << "s " << s << endl;
    cout << "s1 " << s1 << endl;
    cout
        << "\n=====================" << endl;
    return 0;
}


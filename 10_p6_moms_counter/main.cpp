#include <iostream>
#include <iomanip>
#include "includes/mcounter/mcounter.h"


using namespace std;

void display_count(const MCounter& counter) {
    if (counter.is_error()) {
        cout << "ERROR" << endl;
    } else {
        cout << "Count: " << counter.count() << endl;
    }
}

void test_MCounter() {
    cout << "1" << endl;
    MCounter counter;
    cout << "2" << endl;

    char choice;
    bool done = false;

    cout << "[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it" << endl;

    do {
        cout << "Enter: ";
        cin >> choice;
 
        switch (toupper(choice)) {
            case 'A':
                counter.add_1000();
                break;
            case 'S':
                counter.add_100();
                break;
            case 'D':
                counter.add_10();
                break;
            case 'F':
                counter.add_1();
                break;
            case 'R':
                counter.reset();
                break;
            case 'X':
                done = true;
                break;
        }

        display_count(counter);

    } while (!done);
}

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    test_MCounter();
 
    cout << "\n\n\n=====================" << endl;
    return 0;
}

#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>
#include "../../includes/two_d_functions/two_d_functions.h"
using namespace std;

bool **init_plane();
bool reserve(bool **plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool **plane);

bool **init_plane(){
    int size[] = {4,4,4,4,4,4,4,-1};
    bool** plane = allocate_twod<bool>(size);
    init_twod<bool>(plane, size, false);
    return plane;
}
bool reserve(bool **plane, int row, int seat){
    bool result = read_twod(plane,row,seat);
    if (result == false){
        write_twod(plane,row,seat,true);
        return true;
    }
    return false; 
} 
bool cancel(bool** plane, int row, int seat){
    bool result = read_twod(plane,row,seat);
    if (result){
        write_twod(plane,row,seat,false);
        return true;
    }
    return false;
}
void print_plane(bool **plane){
    bool** row_walker = plane;
    for (int i = 0; i < 7; i++){
        bool *col_walker = *row_walker;
        for (int j = 0; j < 4; j++){
            if (*col_walker == false){
                cout << "X" << " ";
            }
            else {
            cout << char('A'+j) << " ";
            }
        col_walker++;
        }
    cout << endl;
    row_walker++;
    }
}

#endif

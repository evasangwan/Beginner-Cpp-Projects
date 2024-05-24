#ifndef LAB_H
#define LAB_H
#include <iostream>
#include <string>
#include "../../includes/two_d_functions/two_d_functions.h"

using namespace std;

int **init_lab(int* stations){
    int** twod = allocate_twod<int>(stations);
    init_twod(twod, stations, 0);
    return twod;
}
bool login(int** labs, int lab, int station, int id){
    int val = read_twod(labs,lab,station);
    if (val == 0){
        write_twod(labs,lab,station,id);
        return true;
    }
    return false;
}
bool logout(int** labs, int* sizes, int id){
    int* ptr = search_twod<int>(labs, sizes, id);
    if (ptr == nullptr){
        return false;
    }
    while (ptr != nullptr){
        *ptr = 0;
        ptr = search_twod<int>(labs, sizes, id);
    }
    return true;
}

#endif

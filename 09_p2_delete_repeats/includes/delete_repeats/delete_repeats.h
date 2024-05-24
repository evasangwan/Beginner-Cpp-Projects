/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : 09_p2_delete_repeats
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 17 2023
 ****************************************************/
#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H
#include <iostream>
#include <string>
#include "../../includes/array_functions/array_functions.h"
using namespace std;

//function delete_repeats deletes all of the duplicate values in an array of any type. 
template <class T>
void delete_repeats(T *a, int &size) {
    if (size <= 1) {
        return;                                     //nothing to delete if size is 0 or 1
    }
    
    T *ptr = a;                                     //ptr points to first element of a

    while (ptr < a + size - 1) {                    //while ptr is less than size -1
        T *tempSearchPtr = ptr;                     //tempSearchPtr will start +1 from ptr,so it points to the next pos
        tempSearchPtr++;
        T *searchPtr = search_entry(tempSearchPtr, a + size - tempSearchPtr, *ptr);    //searchPtr is the address of where the next value of *ptr was found   

        while (searchPtr != nullptr) {              //while searchPtr != nullptr means while it is found
            shift_left(a, size, searchPtr);         //shift it to the left and delete
            searchPtr = search_entry(tempSearchPtr, a + size - tempSearchPtr, *ptr);   // //no need to increment tempSearchPtr as the next val is already in pos after being shifted left
        }
        ptr++;                                      //if searchPtr == nullptr, that means theres only one value and you can move on to search for the next one
    }
}




#endif
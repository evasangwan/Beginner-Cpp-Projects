/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : 09_p6 Add Entry
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 17 2023
 ****************************************************/
#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>
#include <string>
#include "../../includes/array_functions/array_functions.h"
using namespace std;

//function add_entry adds a value to the end of the array
template<class T>
T* add_entry(T* list, const T& new_entry,
                  int& size, int& capacity){
    if (size >= capacity){                                    //if size is greater than or equal to the capacity
        capacity *= 2;                                        //double capacity
        T* newList = reallocate(list, size, capacity);        //reallocate func returns a ptr pointing to first element of new dynamic arr
        list = newList;                                       //since list was deleted in reallocate, list = newList
    }
    T* ptr = list;                              //ptr points to first element in list
    for (int i = 0; i < size; i++){             //loop runs size times
        ptr++;                                 //list ptr is walked through that many times
    }
    *ptr = new_entry;                          //value of list is now value of the new_entry
    size++;                                    //increment size
    return list;                               //return ptr
}
   
                  
//function remove_entry removes the value given 
template<class T>
T* remove_entry(T* list, const T& delete_me,
                     int& size, int& capacity){
    int index = search(list,size, delete_me);               //search returns the index of the value that needs to be deleted 
    if (index >= 0) {
    shift_left(list, size, index);                          //shift_left takes that index and deletes it there
    if (capacity == size *4){                               //if capacity/size is 4, then reduce capacity by half
        capacity /= 2; 
        T* newList = reallocate(list, size, capacity);      //newList points to the new dynamic arr 
        list = newList;                                     //since list was deleted in reallocate, list = newList   
    }
    }
    T*ptr = list;                                           //ptr points to the first element of list
    return ptr;                                             //ptr is returned
}

//remove_last_entry removes the last entry of the array 
template <class T>
T *remove_last_entry(T *list, T &popped,
                     int &size, int &capacity){
    if (size > 0){
    T*walker = list;                              //walker points to the first element in list 
    for (int i = 0; i < size -1; i++){
        walker++;                                 //increment walker size -1 times
    }
    popped = *walker;                             //popped is populated with the value of walker at the end of the array
    shift_left(list, size, walker);               //shift_left deletes the last entry
    if (capacity == size *4){                     //checks if capacity/size is 4, then reduces capacity by half
    capacity /= 2;
    T* newList = reallocate(list, size, capacity);      //newList points to the new dynamic arr 
    list = newList;                                     //since list was deleted in reallocate, list = newList   
}
    }
    T*ptr = list;                                 //ptr points to the first element is list 
    return ptr;                                   //ptr is returned 
}

//insert_entry inserts an entry into the specified position in the arr
template <class T>
T *insert_entry(T *list, const T &insert_this,
                int insert_here,
                int &size,
                int &capacity){
    if (size >= capacity){                                //if size is greater than or equal to the capacity
    capacity *= 2;                                        //double capacity
    T* newList = reallocate(list, size, capacity);        //reallocate func returns a ptr pointing to first element of new dynamic arr
    list = newList;                                       //since list was deleted in reallocate, list = newList
    }
    T* ptr = list;                                        //ptr points to the first element in list 
    if (insert_here >= 0 && insert_here <= size) {
    shift_right(list, size, insert_here);                 //shift_right is called to make space 
    for (int i = 0; i < insert_here; i++){
        ptr++;                                           //list is moved insert_here-0 times  
    }
    *ptr = insert_this;                                  //at position insert_here, list is dereferenced with value insert_this  
    }
    return list;                                           //ptr is returned 
}

//erase_entry erases the value at the given index 
template <class T>
T *erase_entry(T *list, int index,
               int &size, int &capacity){
    if (index >= 0 && index < size) {
    shift_left(list, size, index);                          //shift_left takes that index and deletes it there
    if (capacity == size *4){                               //if capacity/size is 4, then reduce capacity by half
        capacity /= 2;
        T* newList = reallocate(list, size, capacity);      //newList points to the new dynamic arr 
        list = newList;                                     //since list was deleted in reallocate, list = newList   
    }
    }
    return list;                                             //list is returned
    }


#endif
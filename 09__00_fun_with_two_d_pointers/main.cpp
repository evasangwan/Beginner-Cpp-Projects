/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : 09_00 Fun with Two D Pointers 
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 20 2023
 ****************************************************/
#include <iostream>
#include <iomanip>
#include "includes/array_functions/array_functions.h"

using namespace std;
//***************************************************************
//function declarations:
template <class T>
T** allocate_twod(int* sizes);

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
void print_twod(T** twod, int* sizes);

template<class T>
void init_twod(T** twod, int* sizes, T init_item = T());
//***************************************************************

//allocate twod takes in ptr that points to sizes_array(num of cols at each row)
template <class T>
T** allocate_twod(int* sizes){
    int count = 0;                            //to find the number of rows: first set count to 0
    int *ptr = sizes;                         //ptr points to sizes
    while (*ptr != -1){                       //end of sizes_array is -1, to know how many rows there are
        count++;                              //increment count 
        ptr++;                                //increment ptr
    }
    T** twod = new T*[count+1];               //declare double pointer and allocate an array of T*s (capacity is count+1 so that you can set last element to null and know when it ends)
    T** row_walker = twod;                    //row_walker points to twod
    for (int i = 0; i < count; i++){          //loop 4 times (for each row)
    T* col_walker = allocate<T>(*sizes);      //allocate an arr of T for each specific row
    *row_walker = col_walker;                 //the address of col_walker is the value of row_walker
    sizes++;                                  //move sizes (to get to the next row)
    row_walker++;                             //increment row_walker (next row)
    }
    row_walker++;                             //when walker reaches the last row
    *row_walker = nullptr;                    //set it to nullptr(so we know when the last row is)
    return twod;                              

}

//read_two returns the value at the given row and col
template <class T>
T read_twod(T** twod, int row, int col){
  T** row_walker = twod;                      //row_walker points to twod
  for (int i = 0; i < row; i++){
        row_walker++;                         //row_walker walks "vertically" till it gets to desired row
    }
   T* col_walker = *row_walker;               //col_walker points to row_walker
    for (int i = 0; i < col; i++){
        col_walker++;                         //col_walker walks "horizontally" till it gets to desired col 
    }
    return *col_walker;                       //returns the value at that location 
}

//write_twod takes the passed row and col and writes the specified value at that location 
template <class T>
void write_twod(T** twod, int row, int col, const T& item){
    T** row_walker = twod;                    //row_walker points to twod
    for (int i = 0; i < row; i++){
        row_walker++;                         //row_walker walks "vertically" till it gets to desired row
    }
    T* col_walker = *row_walker;              //col_walker points to row_walker
    for (int i = 0; i < col; i++){
        col_walker++;                         //col_walker walks "horizontally" till it gets to desired col 
    }
    *col_walker = item;                       //dereference col_walker and it's value = item
    
}

//print_twod prints the multiple arrays with the initialized elements 
template <class T>
void print_twod(T** twod, int* sizes){
    int count = 0;                            //to find the number of rows: first set count to 0 
    int *ptr = sizes;                         //ptr points to sizes 
    while (*ptr != -1){                       //end of sizes_array is -1, to know how many rows there are
        count++;                              //increment count 
        ptr++;                                //increment ptr 
    }
    T**row_walker = twod;                     //row_walker points to twod
    for (int i = 0; i < count; i++){          //loop is iterated the number of count times 
        print_array(*row_walker,*sizes);      //func print_array prints the elements in the first row 
        row_walker++;                         //row_walker is incremented to get to the next row  
        sizes++;                              //sizes is incremented so that we know how many cols there are in the next row 
    }
}

//init_twod initializes all the elements to 0 by default if argument isn't passed, otherwise to the value passed 
template<class T>
void init_twod(T** twod, int* sizes, T init_item){
    T** row_walker = twod;                            //row_walker points to twod 
    int count = 0;                                    //to find the number of rows: first set count to 0 
    int *ptr = sizes;                                 //ptr points to sizes 
    while (*ptr != -1){                               //end of sizes_array is -1, to know how many rows there are
        count++;                                      //increment count 
        ptr++;                                        //increment ptr 
    }
    int*sizeptr = sizes;                              //size_ptr points to sizes 
    for (int i = 0; i < count; i++) {                 //loop iterates count times 
        int* col_walker = *row_walker;                //col_walker points to row_walker 
         for (int j = 0; j < *sizeptr; j++) {         //j represents the cols, loop iterates the num of cols for that row 
            write_twod(twod, i, j, init_item);        //write_twod func is called 
        }
        sizeptr++;                                    //size_ptr is incremented to go to check the next num of cols 
        row_walker++;                                 //row_walker is incremented to move to next row 
    }
}

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    int sizes_array[5] = {5,3,4,2,-1};                     //array of num of cols for each row, -1 marks end of arr 
    int* sizes = sizes_array;                              //pointer sizes points to first element in sizes_array 
    int** p = allocate_twod<int>(sizes);                   //allocate space for each row, and p points to the twod ptr that was returned 
    init_twod(p, sizes);                                   //init_twod initializes all the values to 0 (by default)
    cout << "Initialized arr (0 by default): " << endl;
    print_twod(p,sizes);                                   //print_twod prints the arr
    cout << endl;

    int insert = 1;                                        //insert is the value that's going to be inserted at the specified rows and cols 
    int** row_walker = p;                                  //row_walker points to p 
    int*sizeptr = sizes;                                   //sizeptr points to sizes 
    for (int i = 0; i < 5; i++) {
        int* col_walker = *row_walker;                     //col_walker points to row_walker 
         for (int j = 0; j < *sizeptr; j++) {              //j represents the cols, loop iterates the num of cols for that row 
            write_twod(p, i, j, insert++);                 //write_twod func is called  
        }
        sizeptr++;                                         //size_ptr is incremented to go to check the next num of cols 
        row_walker++;                                      //row_walker is incremented to move to next row 
    }

    cout << "Array after: " << endl;
    print_twod(p,sizes);                                   //print_twod prints the newly initialized arr 
    cout << endl;
    cout << "Changing val at Row 1, Col 2 to 30: " << endl;
    write_twod(p,1,2,30);                                  //changing the value at given row and col to passed value
    cout << endl;
    print_twod(p,sizes);
    cout << endl;
    cout << "Value at Row 1, Col 2: ";
    int val = read_twod(p,1,2);                            //read_twod reads the value of the given row and col 
    cout << val << endl;
    
    cout << "\n\n\n=====================" << endl;
    return 0;
}



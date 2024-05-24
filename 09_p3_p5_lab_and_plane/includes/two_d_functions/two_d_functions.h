#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H
#include <iostream>
#include <string>
#include "../../includes/array_functions/array_functions.h"

using namespace std;

//function declarations 
int array_size(int* sizes);
void print_array(int* a);
bool index_is_valid(int* sizes, int row, int col);

template <class T>
T** allocate_twod(int* sizes);

template <class T>
T** deallocate_twod(T** twod, int size);

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
T& get_twod(T** twod, int row, int col);

template <class T>
void print_twod(T** twod, int* sizes);

template<class T>
void init_twod(T** twod, int* sizes, T init_item = T());

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

template<class T> 
T* search_twod(T** twod, int* sizes, const T& key);
//***************************************************************

//allocate twod takes in ptr that points to sizes_array(num of cols at each row)
template <class T>
T** allocate_twod(int* sizes){
        int count = array_size(sizes);            //count represents the num of rows 
        T** twod = new T*[count+1];               //declare double pointer and allocate an array of T*s (capacity is count+1 so that you can set last element to null and know when it ends)
        T** row_walker = twod;                    //row_walker points to twod
        int* sizes_walker = sizes;
        for (int i = 0; i < count; i++){          //loop 4 times (for each row)
        T* col_walker = allocate<T>(*sizes_walker);      //allocate an arr of T for each specific row
        *row_walker = col_walker;                 //the address of col_walker is the value of row_walker
        sizes_walker++;                                  //move sizes (to get to the next row)
        row_walker++;                             //increment row_walker (next row)
    }                 
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
    int count = array_size(sizes);            //count represents the num of rows 
    int* sizes_walker = sizes;
    T**row_walker = twod;                     //row_walker points to twod
    for (int i = 0; i < count; i++){          //loop is iterated the number of count times 
        print_array(*row_walker,*sizes_walker);      //func print_array prints the elements in the first row 
        row_walker++;                         //row_walker is incremented to get to the next row  
        sizes_walker++;                              //sizes is incremented so that we know how many cols there are in the next row 
    } 
}


//init_twod initializes all the elements to 0 by default if argument isn't passed, otherwise to the value passed 
template<class T>
void init_twod(T** twod, int* sizes, T init_item){
    T** row_walker = twod;                            //row_walker points to twod 
    int count = array_size(sizes);                    //count represents the num of rows 
    int*sizeptr = sizes;                              //size_ptr points to sizes 
    for (int i = 0; i < count; i++) {                 //loop iterates count times 
        for (int j = 0; j < *sizeptr; j++) {         //j represents the cols, loop iterates the num of cols for that row 
            write_twod(twod, i, j, init_item);        //write_twod func is called 
        }
        sizeptr++;                                    //size_ptr is incremented to go to check the next num of cols 
        row_walker++;                                 //row_walker is incremented to move to next row 
    }
}

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col){
    int count = array_size(sizes);                                //count represents the num of rows 
    T**row_walker = twod;                                         //row_walker points to twod
    int* sizes_walker = sizes;
    for (int i = 0; i < count; i++){                              //loop is iterated the number of count times 
        int index  = search(*row_walker,*sizes_walker,key);              //func print_array prints the elements in the first row 
        if (index != -1){
            row = i;
            col = index;
            return true;
        }
        row_walker++;                                             //row_walker is incremented to get to the next row  
        sizes_walker++;                                                  //sizes is incremented so that we know how many cols there are in the next row 
    }
    return false;
    }


template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){
    T**row_walker = twod;                                         //row_walker points to twod
    int* sizes_walker = sizes;
    int row = 0;
    int col = 0; 
    if (search_twod(twod, sizes_walker, key, row, col)){                 //if bool search returns true, meaning it found it
        row_walker += row;                                        //row_walker will go to that row 
        T*col_walker = *row_walker;                                //col_walker will point to that row   
        col_walker += col;                                        //col_walker will go to that col number 
        return col_walker;                                        //returns col_walker  
    }
    return nullptr;                                               //if bool search returns false, returns nullptr
}

template <class T>
T& get_twod(T** twod, int row, int col){
    T** row_walker = twod;                      //row_walker points to twod
    for (int i = 0; i < row; i++){
        row_walker++;                           //row_walker walks "vertically" till it gets to desired row
    }
    T* col_walker = *row_walker;                //col_walker points to row_walker
    for (int i = 0; i < col; i++){
        col_walker++;                           //col_walker walks "horizontally" till it gets to desired col 
    }
    return *col_walker;                         //returns the variable at that location 
}
 
template <class T>
T** deallocate_twod(T** twod, int size){
    T** row_walker = twod;                        //row_walker points to twod
    for (int i = 0; i < size; i++){     
        T* col_walker = *row_walker;     
        delete[] col_walker;
        row_walker++;                             //increment row_walker (next row)
    }
    delete[] twod;
    return nullptr;                          
}


    


#endif

/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : 09_01 Pointer Array Functions 
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 10 2023
 ****************************************************/
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>
#include <string>
using namespace std;


/****************************************************
 * 09_01 Pointer Array Functions 
 * 
 * The following thirteen functions are going to be used 
 * in the future projects that we'll do. 
 * 
 * Some of these functions include allocate, reallocate, 
 * print, print_array, search, search_entry, shift_left, 
 * shift_right, array_string, and copy_array.   
 * 
 ****************************************************/

const int MINIMUM_CAPACITY = 3;             //minimum capacity is 3 by default 

//Allocate function allocates 'capacity' and returns the array
template <class T>
T *allocate(int capacity = MINIMUM_CAPACITY)
{
    T *arr = new T[capacity];  //pointer arr points to first index of newly allocated array of the desired capacity
    return arr;                //return arr
} 

//function print_array prints the size and capacity like this (Size/Capacity) and the array []
template <class T>
void print_array(T *a, int size,
                 int capacity = 0, ostream &outs = cout)
{
    if (a == nullptr){
        return;
    }
    cout << "(" << size << "/" << capacity << ") [";   //prints out size and capacity in given format
    T *p = a;                                         //pointer p points to first element of a
    for (int i = 0; i < size; i++)
    {
        cout << *p << " ";                             //print out element at that index 
        p++;                                            //increment p
    }
    cout << "]";
    cout << endl;
}

//function print prints out the array without the size/capacity 
template <class T>
void print(T *a, unsigned int how_many,
           ostream &outs = cout)
{
    cout << "[ ";
    int *p = a;                              //pointer p points to first element of a
    for (int i = 0; i < how_many; i++)
    {
        cout << "  " << *p;                  //print out element at that index 
        p++;                                 //increment p
        if (i > -1)
        {
            cout << " ";
        }
    }
    cout << "]";
} 

//function search_entry searches for 'find_me' and returns its pointer 
template <class T>
T *search_entry(T *a, int size, const T &find_me)
{
    T *ptr = a;                             //pointer ptr points to first element of a
    for (int i = 0; i < size; i++)
    {
        if (*ptr == find_me)                //check if value of ptr = find_me
        {
            return ptr;                     //return ptr 
        }
        ptr++;
    }
    return nullptr;                         //if not found, return nullptr
} 

//function search searches for 'find_me' and returns its index
template <class T>
int search(T *a, int size, const T &find_me)
{
    for (int i = 0; i < size; i++)        
    {
        if (*a == find_me)                //checks if value of a == find_me
        {
            return i;                     //if so, its index is returned
        }
        a++;
    }
    return -1;                            //if not, returns -1
}

//function shift_left erases the position 'shift_here' and moves the rest of the elements to the left
//shift left at shift_here, erases at shift_here
template <class T>
void shift_left(T *a, int &size, int shift_here)
{
    T *p = a + shift_here + 1;                       //pointer p points to the location after shift_here
    T *q = a + shift_here;                           //pointer q points to shift_here
    for (int i = shift_here; i < size-1; i++)        //loops from 'shift_here' to 'size + 1'
    {
        *q = *p;                                     //copy the value pointed to by p to the location pointed to by q
        q++;                                         //increment q
        p++;                                         //increment p
    }
    size--;
}

// function shift_left erases the position 'shift_here' and moves the rest of the elements to the left
// shift left at shift_here, erases at shift_here
template <class T>
void shift_left(T *a, int &size, T *shift_here)
{
    if (shift_here == nullptr){                      //check if shift_here == nullptr, meaning the number to shift, isn't an element in the array
        return;                                      //if so, return nothing
    }
    int index = shift_here - a;                      //calculate index to find the index of the element to be shifted.
    T *p = a + index + 1;                            //pointer p points to the location after the element to be shifted.
    T *q = a + index;                                //pointer q points to the element to be shifted
    for (int i = index; i < size-1; i++)               //loops from 'shift_here' to 'size'
    {
        *q = *p;                                     //copy the value pointed to by p to the location pointed to by q
        q++;                                         //increment q
        p++;                                         //increment p
    }
    size--;
}



//function shift_right makes a hole to the right after position 'shift_here' and copies its value
template <class T>
void shift_right(T *a, int &size, int shift_here)
{
    T *p = a + size - 1;                             //pointer p points to the last element in the array
    T *q = a + size;                                 //pointer q points to the position one past the last element in the array
    for (int i = size - 1; i >= shift_here; i--)     //loops through the array elements from the end to 'shift_here'
    {
        *q = *p;                                     //copy the value pointed to by p to the location pointed to by q.
        q--;                                         //decrement q as we're going backwards
        p--;                                         //decrement p as well
    }
    size++;                                          //increment the size to accommodate the new element and keep the last element to make sure it doesn't get cut off
}

//function shift_right makes a hole to the right after position 'shift_here' and copies its value
template <class T>
void shift_right(T *a, int &size, T *shift_here)
{
     if (shift_here == nullptr){                     //check if shift_here == nullptr, meaning the number to shift, isn't an element in the array
        return;                                      //if so, return nothing
    }
    int index = shift_here - a;                      //calculate the index of the element to be shifted.
    T *p = a + size - 1;                             //pointer p points to the last element in the array.
    T *q = a + size;                                 //pointer q points to the position one past the last element in the array
    for (int i = size - 1; i >= index; i--)          //loops through the array elements from the end to 'shift_here'
    {
        *q = *p;                                     //copy the value pointed to by p to the location pointed to by q.
        q--;                                         //decrement q as we're going backwards
        p--;                                         //decrement p as well
    }
    size++;                                          //increment the size to accommodate the new element and keep the last element to make sure it doesn't get cut off
}

//function copy_array copies a specific number 'many_to_copy' of elements from the source array 'src' to the destination array 'dest'.
template <class T>
void copy_array(T *dest, const T *src,
                int many_to_copy)
{
    const T* walker = src;
    for (int i = 0; i < many_to_copy; i++)
    {
        *dest = *walker;                        //copy the value pointed to by walker to the location pointed to by dest.
        dest++;                                 //increment dest to move to the right
        walker++;                               //increment walker as well
    }
}

//function copy_array returns a copy of 'src' 
template <class T>
T *copy_array(const T *src, int size)
{
    T *ptr_arr = new T[size];                //new dynamic array with the specified size, has 'ptr_arr' pointing to first element
    T *pointeR = ptr_arr;                    //pointer pointeR points to first element of ptr_arr
    T* ptr = src;                            //pointer ptr points to first element of src
    for (int i = 0; i < size; i++)           //loops through the 'src' array to copy elements to 'ptr_arr'.
    {
        *ptr_arr = *ptr;                     //copies the value pointed to by 'ptr' to the location pointed to by 'ptr_arr'.
        ptr_arr++;                           //increment ptr_arr to move forward
        ptr++;                               //increment ptr as well
    }
    return pointeR;                          //returns pointeR (points to the newly created and populated 'ptr_arr')
} 

//function reallocate takes the array, resizes it, returns the new array, and deletes the old one
template <class T>
T *reallocate(T *a, int size, int capacity)
{
    T *ptr = allocate<T>(capacity);          //allocates a new dynamic array 'ptr' with the specified 'capacity'.
    copy_array<T>(ptr, a, size);             //passes through func copy_array to copy the elements from the old array 'a' to the new array 'ptr'
    delete[] a;                              //releases arr a
    return ptr;                              //returns pointer to the newly created and populated 'ptr' array
} 

//function array_string returns the array as a string
template <class T>
string array_string(const T *a, int size)
{
    string strArr = "[";                               //initializes an empty string 'strArr' to represent the array as a string.
    if (size > 0)                                      //check if 'size' of the array is greater than 0.
    {
        for (int i = 0; i < size - 1; i++)             //iterate through the elements of the array.
        {
            strArr += to_string(*a) + ", ";            //convert the current element of the array to a string and append it to 'strArr' with a comma and space.
            a++;                                       //increment a to move forward
        }
        strArr += to_string(*a);                       //append the last element of the array to 'strArr' as a string.
    }
    strArr += "]";                                     //add a closing square bracket to 'strArr'.
    strArr += " [" + to_string(size) + "]";
    return strArr;                                     //return 'strArr', which represents the array as a string.
}

#endif
#include "array_functions.h"
#include "assert.h"

//_array_init is a function that initializes an integer array a of
// a given size to a specified value x. It iterates through the array 
//and sets each element to x.
void _array_init(int a[], int size, int x){
for (int i = 0; i < size; i++){
    a[i] = x;
}
}

//_append is a function that appends an integer value append_me 
// to the end of an integer array a. It also increments the size 
// parameter to indicate the new size of the array after appending.
void _append(int a[], int& size, int append_me){
a[size++] = append_me;
}

//_find is a function that is intended to find an integer value
// find_me within an integer array
int _find(const int a[], int size, int find_me){
for (int i = 0; i < size; i++) {
if (a[i] == find_me) {
    return i; // Return the index where 'find_me' is found.
}
}
    return -1; // Return -1 if 'find_me' is not found in the array.
}

// _at is a function that returns a reference to an element of an integer array a 
//at a specified position pos. It first checks if pos is within the valid range 
// (less than size) using the assert function from the <assert.h> header.
int& _at(int a[], int size, int pos){
    assert (pos < size);
    return a[pos];

}

//_print_array is a function that prints the contents of an integer
// array a to an output stream (typically, cout). It formats the output
// as a comma-separated list enclosed in square brackets. The function 
//returns the output stream outs.
ostream& _print_array(const int a[], int size, ostream& outs){
outs << "[";
for (int i = 0; i < size; i++){
    outs << a[i] << "|";
}
outs << "]";
return outs;
}
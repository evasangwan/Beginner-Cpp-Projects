/*****************************************************
 * AUTHOR: Eva Sangwan
 * LAB   : EXTRA CR: Fun with Pointers 
 * CLASS : CS003A
 * SECTION : 1 - 2:30 Mon && Wed, 1 - 3 Tue && Thurs
 * DUE DATE: September 5 2023
 ****************************************************/
#include <iostream>
#include <iomanip>

using namespace std;
/******************************************************
 *
 * EXTRA CR: Fun with Pointers 
 * ____________________________________________________
 * Writing to become familiar with pointers. This includes 
 * declaring pointers of various types (int, char, etc.) and
 * pointing them to various variables, arrays, even each other. 
 * incrementing the pointers, dereferencing, and printing them. 
 *
 *******************************************************/

// swapNumbers is a function that swaps two numbers using pointers
void swapNumbers(int *a, int *b) {
  int num = *a;     //the value pointed to by 'a' is stored in 'num'
  *a = *b;          //the value pointed to by 'b' is assigned to 'a' 
  *b = num;         //num's value is stored in 'b'
}

int main(int argv, char** argc) {
  cout << "\n\n" << endl;


  int *p; //integer pointer declared 
  int *q; //integer pointer declared
  const int size = 5; //size of array
  int arr[size]; //integer array declared

  for (int i = 0; i < size; i++) {
    arr[i] = i * 10; //Initializing the array with some values
  }

  cout << "First element of array: " << arr[0] << endl;
  cout << "Last element of array: " << arr[size - 1] << endl;

  p = &arr[0];   //p holds the address of the first element of arr
  q = &arr[size - 1];   //q holds the address of the last element of arr
  swapNumbers(p, q);    // swapping the first and last elements using swapNumbers function

  cout << "After swapping first and last elements: " << endl;
  cout << "First element of array: " << arr[0] << endl;
  cout << "Last element of array: " << arr[size - 1] << endl;

 //Using pointers to iterate through the array and double each element
  int *ptr = arr;   //declaring pointer, it holds the address of first element of arr
  while (ptr < arr + size) {
    *ptr *= 2;      //doubling each element 
    ptr++;          //moving pointer to next element 
  }

  cout << endl;
  cout << "After doubling each element: " << endl;
  cout << "The first element of the array is: " << arr[0] << endl;

  p = q;      //p and q are now pointing to the same location
  if (p == q){
    cout << "p and q are pointing to the same location now " << endl;
  }
 
   *q = 100;   //the value 100 is assigned to the location q and p are pointing to 
   if ((*q == 100) && (*p == 100)){
    cout << endl;
    cout << "the value 100 is assigned to the location q and p are pointing to " << endl;
   }
 
   cout << "*q = " << *q << endl; 
   cout << "*p = " << *p << endl;

   char ch = 'A';          //declared char ch and initialized it to 'A'.
   char *charPtr = &ch;        //charPtr holds the address of ch, charPtr "points" to ch.
   cout << "*charPtr = " << *charPtr << endl;


   cout << "\n\n\n=====================" << endl;
   return 0;
}





 

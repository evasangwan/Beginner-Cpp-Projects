/*************************************
 * AUTHOR: Eva Sangwan
 * LAB # : Lab 00- WriteUp
 * CLASS : CS003A
 * SECTION : 1 - 2:30, Mon && Wed, 1 - 3, Tue && Thurs
 * DUE DATE: September 5, 2023
 ************************************/
#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/stub/stub.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;

/*************************************
 * LAB 00 - WriteUp
 * 
After implementing the _array_init and _print_array functions, testB writes a simple test 
that verifies whether the _init function works as it should.

The test function is boolean. It returns true if the init function works properly and false 
if not.

This function calls the _array_init function and then goes through it to verify that each element is -1.

If it finds a cell that is not -1, it returns false.
 ************************************/


// ************************************
// test_stub 
// ************************************
// Is a test function which controls whether debug messages are printed. 
// Inside the function, it checks if debug is true, and if so, it prints
// a message indicating that the function is being entered. 
// The function always returns true, indicating that the test has passed.
bool test_stub(bool debug = false)                            
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

// ************************************
// test_at function 
// ************************************
// Tests the behavior of the _at function.
// It initializes an integer array a with a maximum size of 20 and sets size to 5.
// If debug is true, it prints debug information about the array initialization.
// It iterates through the array, and calls _at to access elements and check if 
// the returned values match -1. It then modifies an element in the array and 
// checks if the modification was successful.
// The function returns true if all tests pass; otherwise, it returns false.

bool test_at(bool debug = false){
  int a[20];
  int size = 5;
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: 5, init array to -1" << endl;
  }
  _array_init(a, size, -1);
  if (debug) {
    cout << tabs;
    _print_array(a, size);
    cout << endl;
  }
  int at_i;
  for (int i = 0; i < size; i++){
    at_i = _at(a, size, i);
    if (at_i != -1){
      cout << "FAILED: Expected at(i) to return -1, but found : " << at_i << endl;
      return false;
    }
  }
  _at(a, size, 3) = 300;
  at_i = _at(a, size, 3);
  if (at_i != 300){
  cout << "FAILED: Expected to find 300 at(3), but found : " << at_i << endl;
  return false;
  }
  return true;
}

// ************************************
// test_append 
// ************************************
// Tests the behavior of the function _append.
// It initializes an integer array a with a maximum size of 
// 20 and sets size to 5.
// If debug is true, it prints debug information about the array
// initialization. It then appends values to the array using _append 
// and checks if the size and the last element of the array are as expected.
// The function returns true if all tests pass; otherwise, it returns false.
bool test_append(bool debug = false){
  const int MAX = 20; 
  int a[MAX];
  int size = 5;
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: 5, init array to -1" << endl;
  }
  _array_init(a, size, -1);
  if (debug) {
    cout << tabs;
    if (debug) _print_array(a, size);
    cout << endl;
  }
  for (int i = size; i < 10; i++){
    _append(a, size, i*10);
    if (debug){
      cout << tabs << " " << i << ": ";
      _print_array(a, size);
      cout << endl;
    }
  }
  if (size != 10){
    cout << "FAILED: Expected size to be 10, but found " << size << endl;
    return false;
  }
  if (a[size - 1] != (size - 1)* 10){
    cout << "FAILED: Expected " << (size - 1) * 10 << "at a[" << (size - 1) << "] ";
    cout << " but found: " << a[size - 1] << endl;
    return false;
  }
  return true;
  }

// ************************************
// test_init_array
// ************************************
// Tests the behavior of an array initialization function _array_init. 
// It initializes an integer array a with a maximum 
// size of 20 and sets size to 5. If debug is true, it prints debug information
// about the array initialization. It then checks if the elements of the array are
// initialized to -1. The function returns true if all tests pass; otherwise, it returns false.
bool test_init_array(bool debug = false){
  int a[20];
  int size = 5;
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: " << size << ", init array to -1" << endl;}
    _array_init(a, size, -1);
    if (debug){
      cout << tabs;
      _print_array(a, size);
      cout << endl;
    }
    for (int i = 0; i < size; i++){
      if (a[i] != -1){
        cout << "FAILED: Expected -1 at a[" << i << "] but found: " << a[i] << endl;
        return false;
      }
    }
    return true;
  }

// ************************************
//These lines define the actual test cases.
//The first test case checks the test_stub function, expecting it to return 1 (true).
//The second and third test cases check the test_init_array and test_append functions,
// both expecting them to return 1 (true).
// ************************************
TEST(TEST_STUB, TestStub){
EXPECT_EQ(1, test_stub(false));}

TEST(TEST_ARRAY, TestInitArray){
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_init_array(false));
}

TEST(TEST_ARRAY, TestAppend){
EXPECT_EQ(1, test_append(false));
}

//main runs all defined test cases using RUN_ALL_TESTS() and returns the test results.
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


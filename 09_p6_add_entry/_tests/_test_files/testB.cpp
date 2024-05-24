#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <list>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/add_entry/add_entry.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_remove_entry(bool debug = false)
{

  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  // TestCase1: remove from in between
  {
  int arr[10] = {1,2,2,2,3,4,3};
  int size = 7;
  int capacity = 10;
  int *myArr = arr;
  int intToRemove = 4;

  print_array(myArr, size, capacity);
  int *outArr = remove_entry(myArr, intToRemove, size, capacity);
  print_array(outArr, size, capacity);
  // if it removed the desired entry, then pass else fail
  // if the size is one less then pass, else fail
  }

  // TestCase1.5: capacity should be changed
  // {
  //   cout << "Test case 1.5" << endl;
  // int arr[8] = {1,2,3};
  // // int *myArr = new int[8];
  // int *myArr = arr;
  // int *aaa = myArr;
  // *myArr = 1;
  // myArr++; 
  // *myArr = 2;

  // delete[] aaa;
  // cout << "qqqqqqqqqqqqq" << endl;
  
  // }

  // TestCase2: capacity should be changed
  {
    cout << "Test case 2" << endl;
  int arr[8] = {1,2,3};
  int size = 3;
  int capacity = 8;
  int *myArr = arr;
  int intToRemove = 2;

  print_array(myArr, size, capacity);
  cout << "original" << endl;
  int *outArr = remove_entry(myArr, intToRemove, size, capacity);
  cout <<"removed entry....." << endl;
  print_array(outArr, size, capacity);
  // if it removed the desired entry, then pass else fail
  // if the size is one less then pass, else fail
  }
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1, test_remove_entry(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


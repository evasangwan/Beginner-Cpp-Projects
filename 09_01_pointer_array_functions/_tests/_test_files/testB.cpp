#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

void fill_array(int* src, int size){
  for (int i = 0; i<size; i++){
    src[i] = i*10;
  }
}

 bool test_array_functions(bool debug = false)
{
  if (debug){
    cout << "testB:: test-array_functions() entering test_array_functions" << endl;
  }
  int size = 6;
  int capacity = 20;

  int arr[10] = {1,2,3,4,5,6,7};
  int arr_size = 5;
  int arr_index = 2;

  print_array(arr, arr_size, capacity);
  shift_left(arr, arr_size, arr_index);
  print_array(arr, arr_size, capacity);

  int *_arr = allocate<int>(capacity);
  fill_array(_arr, size);
  print_array(_arr, size, capacity);

  int key = 10;
  int *found = search_entry(_arr, size, key);
   if (found){
    cout << "key was found: " << *found << endl;
  }
  else{
    cout << "key was not found" << endl;
  }

  key = 30;
  int index = search(_arr, size, key);
  if (index>=0){
    found = _arr + index;
    cout << *found << " was found at index: " << index << endl;
  }
  else{
    cout << "key was not found" << endl;
  }

  int copy_arr[15];
  copy_array(copy_arr, _arr, size); 
  print_array(copy_arr, size, capacity); 

  int *p;
  key = 50;
  cout << "shift right at "<<key<<":";
  p = search_entry(_arr, size, key);
  shift_right(_arr, size, p);
  print_array(_arr, size, capacity);

  size = 3;
  cout << "changed size of _arr" << endl;
  print_array(_arr, size, capacity);

  key = 20;
  cout << "shift left at "<<key<<":";
  p = search_entry(_arr, size, key);
  shift_left(_arr, size, p);
  print_array(_arr, size, capacity);

  key = 10;
  cout << "shift left at "<<key<<":";
  p = search_entry(_arr, size, key);
  shift_left(_arr, size, p);
  print_array(_arr, size, capacity);

  key = 0;
  cout << "shift left at "<<key<<":";
  p = search_entry(_arr, size, key);
  shift_left(_arr, size, p);
  print_array(_arr, size, capacity);

  size = 4;         //changed size back
  print_array(_arr, size, capacity);
  cout << "shift left worked properly " << endl;
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1, test_array_functions(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}




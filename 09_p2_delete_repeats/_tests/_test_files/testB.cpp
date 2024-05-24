#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/delete_repeats/delete_repeats.h"
#include "../../includes/array_functions/array_functions.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_delete_repeats(bool debug = false)
{
  if (debug){
    cout << "testB:: test_delete_repeats() entering test_delete_repeats" << endl;
  }
  char a[40] = "aababkallsdkjtqpocdhwrjqqqabcdabcdef";
  int size = strlen(a);
  cout << "\n\noriginal list: ";
  print_array(a, size);
  cout << endl;

  delete_repeats(a, size);
  cout << "\n\nunique values: ";
  print_array(a, size);
  cout << endl;

  int b[30] = {1,1,1,1,1,1,1,1,1,1,1};
  size = 11;
  cout << "\n\noriginal list: ";
  print_array(b, size);
  cout << endl;

  delete_repeats(b, size);
  cout << "\n\nunique values: ";
  print_array(b, size);
  cout << endl;
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1,test_delete_repeats(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


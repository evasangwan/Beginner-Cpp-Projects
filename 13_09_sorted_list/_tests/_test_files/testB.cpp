#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/list_sorted/list_sorted.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

bool test_insert_add(bool debug = false){
  List<int> list(true,true);
  cout << "list.empty(): " << boolalpha << list.empty() << endl;
  for (int i = 1; i < 6; i++)
  {
    list.insert(i);
    list.insert(i * 10);
    list.insert(i * 100);
  }
   cout << list << endl;
  list.insert(1);
  cout << "list after inserting 1 again " << endl;
  cout << list <<endl;
  List<int>::Iterator it = list.search(4);
  cout << "found 4: " << *it << endl;
  it = list.prev(it);
  return true;

}


TEST(TEST_INSERT_ADD, TestStub){
  EXPECT_EQ(1,test_insert_add(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


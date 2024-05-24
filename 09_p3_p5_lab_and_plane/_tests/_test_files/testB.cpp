#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/lab/lab.h"
#include "../../includes/plane/plane.h"
#include "../../includes/two_d_functions/two_d_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_twod_lab_and_plane(bool debug = false)
{
  if (debug){
    cout << "testB:: test_lab_and_plane() entering test_lab_and_plane" << endl;
  }
  int sizes[] = {4,6,2,5,-1};
  cout << "allocating (allocate_twod)" << endl;
  int **td = allocate_twod<int>(sizes);

  cout << "initializing all to 0 (init_twod)" << endl;
  init_twod(td, sizes, 0);
  print_twod(td, sizes);

  cout << "writing values at specific row/col (write_twod)" << endl;
  write_twod(td, 0, 3, 1);
  write_twod(td, 1, 1, 2);
  write_twod(td, 3, 4, 4);
  cout << endl;
  print_twod(td, sizes);
  cout << endl;

  cout << "reading the values at specified row/col (read_twod)" << endl;
  cout << "[0][3]: " << read_twod(td, 0, 3)<< endl;
  cout << "[1][1]: " << read_twod(td, 1, 1)<< endl;
  cout << "[3][4]: " << read_twod(td, 3, 4)<< endl;

  int row;
  int col;
  cout << "using search_twod to find value 4 at which row/col" << endl;
  bool found = search_twod(td, sizes, 4, row, col);
  if (found){
    cout << "\nfound 4 at: [" << row << "][" << col << "]" << endl;
  }
  cout << "search_twod works" << endl;
  cout << endl;

  cout << "Testing index_is_valid: " << endl;
  bool valid;
  row = 3;
  col = 4;
  valid = index_is_valid(sizes, row, col);
  if (valid){
    cout << "td[" << row << "][" << col << "] is a valid location." << endl;
  }
  else{
    cout << "td[" << row << "][" << col << "] is NOT a valid location." << endl;
  }

  row = 1;
  col = 7;
  valid = index_is_valid(sizes, row, col);
  if (valid){
    cout << "td[" << row << "][" << col << "] is a valid location." << endl;
  }
  else{
    cout << "td[" << row << "][" << col << "] is NOT a valid location." << endl;
  }

  cout << endl;
  cout << "testing deallocate: " << endl;
  td = deallocate_twod(td, 4);
  cout << "deallocated successfully " << endl;

  cout << endl;
  cout << "testing lab now" << endl;
  print_array(sizes);
  int** labs = init_lab(sizes);
  print_twod(labs, sizes);
  int lab;
  int station;
  int id;
  cout << "testing login" << endl;
  lab = 0;
  station = 2;
  id = 999;
  login(labs, lab, station, id); 
  cout << "login successful" << endl;
  print_twod(labs, sizes);

  lab = 0;
  station = 2;
  id = 100; 
  if(login(labs, lab, station, id)){
    cout << "login failed, this space is already logged in" << endl;
  }
  else {
    cout << "login successful" << endl;
  }
  print_twod(labs, sizes);
  cout << endl;
  cout << "testing logout " << endl;
  id = 56; 
  if (logout(labs,sizes,id)){
    cout << "logout failed, can't logout someone who wasn't logged in" << endl;
  }
  else {
    cout << "logout successful" << endl;
  }

  id = 999; 
  if (logout(labs,sizes,id)){
    cout << "logout successful" << endl;
  }
  else {
    cout << "logout failed, can't logout someone who wasn't logged in" << endl;
  }
  print_twod(labs, sizes);
  cout << endl;
  cout << "deallocating now" << endl;
  int count = array_size(sizes);
  labs = deallocate_twod(labs, count);

  cout << endl;
  cout << "--------------------------" << endl;

  cout << endl;
  cout << "testing plane" << endl;
  bool** plane = init_plane();
  cout << "init successfully " << endl;
  print_plane(plane);
  
  int seat;
  row  = 0;
  seat = 3;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  reserve(plane, row, seat); 
  cout << "reserved successfully" << endl;
  print_plane(plane);

  row  = 0;
  seat = 3;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  if(reserve(plane, row, seat)){
    cout << "reserved successfully" << endl;
  }
  else{
    cout<<"failed can't reserve a seat that's already occupied"<<endl;
  }
  print_plane(plane);

  row = 4;
  seat = 3;
  cout << "testing cancel" << endl;
  cout << "\ncancelled "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  if(cancel(plane, row, seat)){
    cout << "  FAIL: this seat was not occupied, but canceled!" << endl;
  }
  else{
    cout<<"   cancel() correctly refused to cancel unoccupied seat."<<endl;
  }
  print_plane(plane);

  row = 0;
  seat = 3;
  cancel(plane, row, seat);
  cout << "cancelled successfully" << endl;
  cout << "\ncancelled "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  print_plane(plane); 

  cout << "deallocating" << endl;
  plane = deallocate_twod(plane, 7);
  return true;
}


TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1, test_twod_lab_and_plane(false));

}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


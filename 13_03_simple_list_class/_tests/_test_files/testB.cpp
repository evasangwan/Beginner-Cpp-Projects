#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_simple/list_simple.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_search_list(bool debug = false){
    node<int>* head = nullptr;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    node<int>* node3 = _search_list(head, 3);
    node<int>* node7 = _search_list(head, 7);
    node<int>* node2 = _search_list(head, 2); //should return nullptr
    _print_list(head);
    cout << endl;
    if (node3 != nullptr) {
        cout << "node [3] found: " << *node3 << endl;
    } else {
        cout << "node [3] not found!!" << endl;
    }

    if (node7 != nullptr) {
        cout << "node [7] found: " << *node7 << endl;
    } else {
        cout << "node [7] not found!!" << endl;
    }

    if (node2 != nullptr) {
        cout << "node [2] found: " << *node2 << endl; // Should not be reached
    } else {
        cout << "node [2] not found(as expected)!!" << endl;
    }

    // Clean up the memory (delete the linked list)
    _clear_list(head);
  return true;
}

bool test_insert_after(bool debug = false){
    node<int>* head = nullptr;
    cout << "testing insert_after" << endl;
    cout << "testing when head is null " << endl;
    cout << "list " << endl;
    _print_list(head);
    head = _insert_after(head, head, 182);
    cout << "outcome " << endl;
     _print_list(head);
     cout << endl;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "List before " << endl;
    _print_list(head);
    cout << endl;
    node<int>* node5 = _search_list(head, 5);
    head = _insert_after(head,node5, 99);
    cout << "Changed list: " << endl;
    _print_list(head);
    node<int>* node7 = _search_list(head, 7);
    head = _insert_after(head,node7, 100);
    cout<< endl;
    cout << "Changed list: " << endl;
    _print_list(head);

  return true;
}

bool test_insert_before(bool debug = false){
    cout << endl;
    cout << "testing insert before" << endl;
    node<int>* head = nullptr;
      _print_list(head);
      cout << endl;
       head = _insert_before(head, head, 99);
         _print_list(head);
      cout << endl;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "List before " << endl;
    _print_list(head);
    cout << endl;
    node<int>* node5 = _search_list(head, 5);
    head = _insert_before(head, node5, 99);
    cout<< endl;
    cout << "Changed list(before 5 should be 99): " << endl;
    _print_list(head);
    node<int>* node7 = _search_list(head, 7);
    head = _insert_before(head, node7, 100);
    cout<< endl;
    cout << "Changed list(before 7, should be 100): " << endl;
    _print_list(head);
    cout << endl;
    return true;
}

bool test_delete_node(bool debug = false){
    cout << "testing delete " << endl;
    node<int>* head = nullptr;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "initial list " << endl;
    _print_list(head);
    cout << endl;
    node<int>* node1 = _search_list(head, 1);
    int num0 = _delete_node(head,node1);
    cout << "list after deleting 1" << endl;
    _print_list(head);
    cout << endl;
    node<int>* node3 = _search_list(head, 3);
    int num = _delete_node(head,node3);
    cout << "list after deleting 3" << endl;
    _print_list(head);
    cout << endl;
    node<int>* node7 = _search_list(head, 7);
    int num2 = _delete_node(head,node7);
    cout << "list after deleting 7 " << endl;
    _print_list(head);
    cout << endl;
    node<int>* node5 = _search_list(head, 5);
    int num3 = _delete_node(head,node5);
    cout << "list after deleting 5" << endl;
    _print_list(head);
    cout << endl;
    cout << "testing deleting head " << endl;
    head = nullptr;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "initial list " << endl;
    _print_list(head);
    cout << endl;
    node<int>* node_7 = _search_list(head, 7);
    int num9 = _delete_node(head,node_7);
    cout << "list after deleting 7" << endl;
    _print_list(head);
    cout << endl;
  return true;
}

bool test_clear_list(bool debug = false){
    cout << "testing clear list " << endl;
    node<int>* head = nullptr;
    //  _print_list(head);
    // _clear_list(head);
    //  _print_list(head);
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "initial list " << endl;
    _print_list(head);
    cout << endl;
    _clear_list(head);
     cout << " list after _clear_list" << endl;
    _print_list(head);
    cout << endl;
  return true;
}

bool test_at(bool debug = false){
    node<int>* head = nullptr;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    head = _insert_head(head, 7);
    cout << "list " << endl;
    _print_list(head);
    cout << endl;
    int item = _at(head,0);
    cout << "At index 0 " << endl;
    cout << item << endl;
    // int itemm = _at(head,6);
    // cout << "At index 6 " << endl;
    // cout << item << endl;
    int iteM = _at(head,3);
    cout << "At index 3 " << endl;
    cout  << iteM << endl;
    cout << endl;
     int iteM_ = _at(head,4);
    cout << "At index 4 " << endl;
    cout  << iteM_ << endl;
    cout << endl;
  return true;
}

bool test_previous_node(bool debug = false){
    cout << "Testing prev node" << endl;
    node<int>* head = nullptr;
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    _print_list(head);
    cout << endl;
    node<int>* node3 = _search_list(head, 3);
    if (node3 != nullptr) {
        cout << "node to find prev node to: " << *node3<< endl;

        node<int>* prevNode = _previous_node(head, node3);

        if (prevNode != nullptr) {
            cout << "prev node: " << *prevNode << endl;
        } else {
            cout << "prev node not found (head node/nullptr)" << endl;
        }
    } 
    node<int>* node1 = _search_list(head, 1);
    if (node1 != nullptr) {
        cout << "node to find prev node to: " << *node1<< endl;

        node<int>* prevNode = _previous_node(head, node1);

        if (prevNode != nullptr) {
            cout << "prev node: " << *prevNode << endl;
        } else {
            cout << "prev node not found (head node/nullptr)" << endl;
        }
    } 
    return true;
}

bool test_wherethisgoes(bool debug = false){
    cout << "testing where this goes " << endl;
    node<int>* head = nullptr;
    head = _insert_head(head, 7);
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    cout << "list " << endl;
    _print_list(head);
    cout << endl;
    node<int>* afterwhich = _where_this_goes(head, 4);
    cout << *afterwhich << endl;
    // node<int>* afterwhich_ = _where_this_goes(head, 0);
    // cout << *afterwhich_ << endl;
    node<int>* afterwhicH = _where_this_goes(head, 9);
    cout << *afterwhicH << endl;
    node<int>* afterwhich_ = _where_this_goes(head, 0); //item is less than head->_item
    cout << afterwhich_ << endl;   //returns nullptr
    cout << endl;
    cout << "testing where this goes DESCENDING  " << endl;
    head = nullptr;
    head = _insert_head(head, 1);
    head = _insert_head(head, 3);
    head = _insert_head(head, 5);
    head = _insert_head(head, 7);
    cout << "list " << endl;
    _print_list(head);
    cout << endl;
    bool ascending = false;
    node<int>* after_which_one = _where_this_goes(head, 4, ascending);
    cout << *after_which_one << endl;
  return true; 
}

bool test_insert_sorted(bool debug = false){
    cout << "testing _insert_sorted " << endl;
    node<int>* head = nullptr;
    cout << "initial " << endl;
     _print_list(head);
    head = _insert_sorted(head,100);
    cout << "after inserting 100 " << endl;
     _print_list(head);
    head = _insert_head(head, 7);
    head = _insert_head(head, 5);
    head = _insert_head(head, 3);
    head = _insert_head(head, 1);
    cout << "list " << endl;
    _print_list(head);
    cout << endl; 
    head = _insert_sorted(head,10);
    cout << "after inserting 10 " << endl;
     _print_list(head);
    cout << endl; 
    head = _insert_sorted(head,0);
    cout << "after inserting 0 " << endl;
     _print_list(head);
    cout << endl; 
    head = _insert_sorted(head,2);
    cout << "after inserting 2 " << endl;
     _print_list(head);
     cout << endl; 
  return true;
}





TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1, test_search_list(false));
  EXPECT_EQ(1, test_insert_after(false));
  EXPECT_EQ(1, test_insert_before(false));
  EXPECT_EQ(1, test_previous_node(false));
  EXPECT_EQ(1, test_delete_node(false));
  EXPECT_EQ(1, test_clear_list(false));
  EXPECT_EQ(1, test_at(false));
  EXPECT_EQ(1, test_wherethisgoes(false));
  EXPECT_EQ(1, test_insert_sorted(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
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

bool test_rpn(bool debug = false)
{
  // Queue<Token *> postfix;
  // postfix.push(new Integer(24));
  // postfix.push(new Integer(3));
  // postfix.push(new Operator("*"));
  // RPN rpn(postfix);
  // cout << "24 3 *: " << rpn() << endl;
  // cout << "-------------" << endl;
  // Queue<Token *> postfix2;
  // postfix2.push(new Integer(24));
  // postfix2.push(new Integer(3));
  // postfix2.push(new Operator("/"));
  // RPN rpn2(postfix2);
  // cout << "24 3 /: " << rpn2() << endl;
  // cout << "-------------" << endl;
  // Queue<Token *> postfix3;
  // postfix3.push(new Integer(24));
  // postfix3.push(new Integer(3));
  // postfix3.push(new Operator("-"));
  // RPN rpn3(postfix3);
  // cout << "24 3 -: " << rpn3() << endl;
  // cout << "-------------" << endl;
  // Queue<Token *> postfix4;
  // postfix4.push(new Integer(5));
  // postfix4.push(new Integer(24));
  // postfix4.push(new Integer(3));
  // postfix4.push(new Operator("/"));
  // postfix4.push(new Operator("+"));
  // RPN rpn4(postfix4);
  // cout << "ans should be 13 " << endl;
  // cout << "5 24 3 / +: " << rpn4() << endl;
  // cout << "-------------" << endl;
  return true;
}

TEST(TEST_RPN, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_rpn(false));
}


bool test_shuntingyard(bool debug = false)
{
  cout << "here " << endl;
  //ShuntingYard sy("X^2 + 3X *(4X^2)");
  //ShuntingYard sy("cos(3.4) + tan(3.4)");
  //ShuntingYard sy("( 2.5 + 3.8 ) * ( 4.2 - 1.6 ) + ( 5.7 / 2.1 ) - ( sin ( 0.8 ) + cos ( 1.2 ) ) * ( tan ( 10 )");
  //ShuntingYard sy("sin ( cos ( x ) + tan ( x ) )");
  //ShuntingYard sy("16* sin(1/x) + 78");
  //ShuntingYard sy("sin ( 30 ) + cos ( 45 )");
  //ShuntingYard sy("2 - sin(X * 3 - X)");
  //ShuntingYard sy("cot(x^2)");
  //ShuntingYard sy("sec(csc(x))");
  //ShuntingYard sy("sin(1/x)");
  //ShuntingYard sy("cot(-x^2)"); //doesnt do this correction: does this now! :D 
  // ShuntingYard sy("sin(-x^3)");
  // ShuntingYard sy("x^sin(x)");
  ShuntingYard sy("x/0");
  // ShuntingYard sy("x^-1");
  // ShuntingYard sy("(^2)");
  //ShuntingYard sy ("sin(x^-1)");
  // ShuntingYard sy("sin(csc(tan(x)))");

  Queue<Token*> p = sy.postfix();
  RPN rpN(p);
  // cout << p << endl;
  // for (int i = -5; i <= 5; i++){
  //   cout << "("<<i << ", " << rpN(i) << ")" << endl;
  // }
  cout << rpN(4) << endl;
  // cout << rpN(3) << endl;
  cout << "doneeee " << endl;
  // Queue<Token *> infix;
  // // infix.push(new Integer(10));
  // // infix.push(new Operator("/"));
  // // infix.push(new Integer(2));
  // // infix.push(new Operator("+"));
  // // infix.push(new Integer(3));
  // infix.push(new Integer(-3));
  // infix.push(new Operator("+"));
  // infix.push(new Integer(-4));
  // // infix.push(new Operator("+"));
  // // infix.push(new Integer(3));
  // ShuntingYard sy(infix);
  // Queue<Token*> p = sy.postfix();
  // RPN rpN(p);
  // cout << p << endl;
  // cout << "10 / 2 + 3= " << rpN() << endl;
  // Queue<Token *> infix2;
  // // infix2.push(new Integer(20));
  // // infix2.push(new Operator("-"));
  // // infix2.push(new Integer(2));
  // // infix2.push(new Operator("*"));
  // // infix2.push(new Integer(3));
  // // infix2.push(new Operator("+"));
  // infix2.push(new Function("X"));
  // infix2.push(new Operator("^"));
  // infix2.push(new Integer(2));
  // ShuntingYard sy1(infix2);
  // Queue<Token*> p1 = sy1.postfix();
  // RPN rpN1(p1);
  // cout << p1 << endl;
  // for(int i = 0; i <4; i++){
  //   cout << "20 - 2* 3 + i^2= " << rpN1(i) << endl;
  // }
  // cout << "20 - 2* 3 + 4^2= " << rpN1(4) << endl;
  return true;
}  

TEST(TEST_SHUNTINGYARD, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shuntingyard(false));
}


bool test_plotting(bool debug = false){
  Queue<Token *> infix;
  infix.push(new Function("X"));
  infix.push(new Operator("^"));
  infix.push(new Integer(2));
  ShuntingYard sy(infix);
  Queue<Token*> p = sy.postfix();
  RPN rpN(p);
  // cout << p << endl;
  cout << "y = x^2 coordinates: (-5 to 5)" << endl;
   for (int i = -5; i < 6; i++){
    cout << "(" << i << ", " << rpN(i) << ")" << endl;
    // cout << rpN(i) << endl;
  }
  return true;
}

TEST(TEST_PLOTTING, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_plotting(false));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


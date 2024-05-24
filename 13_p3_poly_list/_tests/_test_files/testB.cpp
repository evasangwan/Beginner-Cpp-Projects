#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/list_sorted/list_sorted.h"
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/poly_list/poly.h"
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

bool test_division(bool debug = false)
{
  double p[] = {0.0};
  double q[] = {10.0,8.0,11.0};
  Poly p1(p,0);
  Poly p2(q,2);
  cout << "p1 " << p1 << endl;
  cout << "p2 " << p2 << endl;
  cout << "p1 * p2   " << p1*p2 <<endl;
  Poly product = p1*p2;
  cout << "(p1*p2)/p1 " << product/p1 << endl;
  cout << "        p2 " << p2 << endl;


  return true;
}

TEST(TEST_DIVISION, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_division(false));
}

bool test_add(bool debug = false)
{
  double coefs1[] = {0.0};
  double coefs2[] = {5.0,4.0,9.0};
  Poly p(coefs1, 0);
  Poly q(coefs2, 2);
  cout << "p       " << p << endl;
  cout << "q       " << q << endl;
  cout << "p + q   " << p+q << endl;
  Poly sum = p+q;
  cout << "sum     " << sum << endl;
  cout << "sum - p "<< sum-p << endl;
  cout << "(p+q)-p "<< (p+q)-p << endl;
  cout << "q       " << q << endl;
  if((p+q)-p==q){
    cout << "////////////YES/////////////" <<endl;
  }
  else{
    cout << "///////NO///////////" <<endl;
  }
  // cout << "(p + q)-p " << (p+q)-p << endl;
  // cout << " q        " << q << endl;
  // if ((p+q)-p==q){
  //   cout << "true " << endl;
  // }
  //   ////////////////////////////////////////////
  
  return true;
}

TEST(TEST_ADD, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_add(false));
}

bool test_poly_add_term(bool debug = false){
  //+16.0X^13 +15.0X^12 +49.0X^11 +17.0X^10 +5.0X^9 +48.0X^8 +49.0X^7 +19.0X^6 +12.0X^5 +43.0X^4 +36.0X^3 +31.0X^2 +11.0X +6.0 
  double testing[] = {6,11,31,36,43,12,19,49,48,5,17,49,15,16};
  double testing2[] = {50.0,12.0,5.0,14.0,42.0,30.0,9.0,9.0,5.0,18.0};
  Poly one(testing,13);
  Poly two(testing2,9);
  cout << "one " << one << endl;
  cout << "two " << two << endl;
  cout << "one + two " << one+two << endl;
  cout << " ....... " << (one+two)-one << endl;
  if ((one+two)-one == two){
    cout << "yas queen " << endl;
  }
  else {
    cout << "no " << endl;
  }
  double coefs1[] = {2.0,5.0};
  // double coefs2[] = {3.0,6.0,8.0,4.0,9.0};
  double coefs2[] = {5.0,5.0};
  Poly p(coefs1, 1);
  Poly u(coefs2,1 );
  cout << "p     " << p << endl;
  cout << "u     " << u << endl;
  cout << "p - u " << p-u << endl;
  cout << "p + u " << p + u << endl;
  Poly g = p + u; 
  cout << "g     " << g << endl;
  if ((g- u) == p){
    cout << "g - u " << (g -u) << endl;
    cout << "p " << p << endl;
    cout << "yes " << endl;
  }
  else {
    cout << "g - u " << (g -u) << endl;
    cout << "p " << p << endl;
    cout << "no " << endl;
   
  }
  Term q(0, 1);
  cout << q << endl;
  Poly r(coefs2,0);
  cout << "p " << p << endl;
  cout << "r " << r << endl;
  cout << "p+=r "<< (p+=r) << endl;
  // cout << "/////////////////////////" << endl;
  cout << "p + r " << p+r <<endl;
  Poly h = p+r; 
  cout << "h " << h << endl;
  if (h - p == r){
    cout << "h - p " << h - p << endl;
    cout << "works " << endl;
  }
  else {
    cout << "h - p " << h - p << endl;
    cout << "nope " << endl;
  }
  cout << "p+= q " << p << endl;
  double coeff[]= {3.0,23.0,3.0};
  double coef_[] = {27,14,40,28,10,47,32,14,49,29,48,9};
  Poly x(coeff, 2);
  Poly y(coef_,11);
  cout << "**********************************" << endl;
  cout << "x + y " << x+y << endl;
  Poly z = x+y;
  cout << "z     " << z << endl;
  cout << "z-x " << z -x << endl;
  Poly v = z - x;
  cout << "v is " << v << endl;
  cout << "y is " << y << endl;
  if ((z-x)==y){
    cout << "yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
    if (v == y){
    cout << "trueeeeeee" << endl;
  }
  else {
    cout << "for z - x == y " << endl;
    cout << "z - x " << z-x << endl;
    cout << "y     " << y << endl;
    cout << "NOPE" << endl;
  }

  return true;
}

TEST(TEST_POLY_ADD_TERM, TestStub){
  EXPECT_EQ(1,test_poly_add_term(false));
}

bool test_poly_times_poly(bool debug = false){
  double coefs1[] = {2.0,5.0};
  double coefs2[] = {3.0,5.0,4.0};
  Poly p(coefs1, 1);
  Poly q(coefs2, 2);
  cout << p << endl;
  cout << q << endl;
  cout << "p * q " << p * q << endl;
  cout << "p*= q " << (p*=q) << endl;
  Term t(9.0,5);
  Term s(0,0);
  cout << "t*=s " << (t*=s) << endl;
  cout << "p*s" << p * s << endl;
  cout << p << endl;
  cout << t << endl;
  cout << "p * t " << p * t << endl;
  return true;
}

TEST(TEST_POLY_TIMES_POLY, TestStub){
  EXPECT_EQ(1,test_poly_times_poly(false));
}


bool test_poly_divide_poly(bool debug = false){
  double coefs1[] = {2.0,2.0};
  double coefs2[] = {4.0,8.0,16.0};
  Poly p(coefs1, 1);
  Poly q(coefs2, 2);
  cout << "q / p " << q / p << endl;
  Poly r = q/p;
  if ((r*p) == q){
    
    cout << "works " << endl;
  }
  else {
    cout << "nope " << endl;
  }
  double coefs3[] = {6.0};
  double coefs4[] = {36.0,24.0,6.0};
  Poly w(coefs3, 0);
  Poly s(coefs4, 2);
  cout << "w " << w << endl;
  cout << "s / w " << s / w << endl;
  Poly t = s/w;
  cout << "t*w" << t*w << endl;
  cout << "s  " << s << endl;
  if ((t*w) == s){
    
    cout << "works " << endl;
  }
  else {
    cout << "nope " << endl;
  }
  double coefs5[] = {0.0};
  double coefs6[] = {36.0,24.0,6.0};
  Poly a(coefs5, 0);
  Poly b(coefs6,2);
  cout << "a / b " << a / b << endl;
  return true;
}
TEST(TEST_POLY_DIVIDE_POLY, TestStub){
  EXPECT_EQ(1,test_poly_divide_poly(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


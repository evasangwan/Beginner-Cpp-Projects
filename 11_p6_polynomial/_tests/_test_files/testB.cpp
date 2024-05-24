#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <cmath> 
#include "../../includes/poly/poly.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}
// void test_multiplication(const Poly& p, const Poly& q){
//   Poly r = p * q;
//   cout << "result is " << r << endl;
//   cout << "p / q " << p / q << endl;
//     cout<<"  rem = "<<p % q<<"  ";
//      if(r * q + p % q == p){
//         cout<<"VERIFIED"<<endl;
//      }
// }

void test_div(const Poly& p, const Poly& q){
    Poly r = p / q;
    cout<<p<<" / "<<q<<endl;
    cout<<"      = "<<r;
    cout<<"  rem = "<<p % q<<"  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if(r * q + p % q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r * q: "<<r * q<<endl;
        cout<<"   p % q: "<<p % q<<endl;
        cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    }
}
bool test_add_poly(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  double coefs1[] = {5.0,1.0,2.0,3.0};
  double coefs2[] = {2.0,24.0,36.0,48.0,4.0};
  double coefs3[] = {2.0, 1.0};
  double coefs4[] = {-9.0,-9.0,-9.0,-9.0,-9.0,-27.0};
  double coefs5[] = {1.0,-5.0};
  double coefs6[] = {3.0,-2.0,0.0,4.0,0.0,6.0};
  double coefs7[] = {5.0,1.0,2.0,3.0,4.0};
  double coefs8[] = {0.0};
   Poly x(coefs7,4);
  Poly c(coefs8,0);
  Poly z(coefs6,5);
  double p2_coefs[] = {-5.0, 1.0, M_PI, -3.147};
    double p1_coefs[] = {5.0, 1.0, 2.0, 3.0, 4.543};
    Poly p1(p1_coefs, 4);
    Poly p2(p2_coefs, 3);
     cout << "???????????????????????????????????????????????????????" << endl;
    cout << p1 * p2 << endl;
    cout << p1 / p2 << endl;
    cout << p1 % p2 << endl;
    cout << "???????????????????????????????????????????????????????" << endl;






  cout << "x * c " << x * c << endl;
  Poly d = x * c; 
  cout << "Poly d = " << d << endl;
  cout << "d / x " << d / x << endl;
  cout << "d % x " << d % x << endl;
  cout << "d / x + d % x " << d / x + d % x <<endl;
  //cout << "????????????????????????????????????" << endl;
  cout << "z * 0 " << z * c << endl;
  Poly g = z * c;
  cout << g << endl;
  cout << "g / z " << g / z << endl;
  cout << "*******************************" << endl;
  Poly r = z * x; 
  if (r / z == x){
    cout << "VERIFIED" << endl;
  }
  else {
    cout << "NOPE" << endl;
  }
  cout << "z * x " << z * x << endl;
  Term t(3,8);
  cout << "z * t " << z * t << endl;
  // test_multiplication(x,z);
  // cout << "z * x " << z * x << endl;
  //test_div(x,z);
  Poly p(coefs1, 3);
   Poly q(coefs2, 4);
  Poly e(coefs3,1);
  Poly y(coefs4, 5);
  Poly h;
  //test_div(q,e);
  // test_div(y,e);
  cout << "p " << p << endl;
  cout << "q " << q << endl;
  cout << " y " << y << endl;
  cout << "e " << e << endl;
  cout << "p * q " << p * q << endl;
  cout << "q * e " << q * e << endl;
  cout << "e * y " << e * y << endl;
  cout << "y * h " << y * h << endl;
  cout << "y / e " << y / e << endl;
  cout << "y%e " << y % e << endl;
  cout << "p / p " << p / p << endl;
  cout << "p / e " << p / e << endl;
  // cout << "p / y " << p / y << endl;
  // cout << "y / p " << y / p << endl;
  cout << "h is " << h << endl;
  cout << "p - p " << p - p << endl;
  cout << "h + p " << p + h << endl;
  // cout << "p " << p << endl;
  // cout << "y " << y << endl;
  // cout << "p + y " << p + y << endl;
  // Term t(3,4);
 
  //Poly e(coefs3,0);
  Poly f(coefs5,1);
  cout << "e + f " << f + e << endl;
  cout << "p + q" << p + q << endl;
  cout << "p * q" << p * q << endl;
  // cout << "p + e" << p + e << endl;
  // cout << "p + e " << p + e << endl; 
  // cout << "p: " << p << endl;
  // cout << "q: " << q << endl;
  // cout << "t: " << t << endl;
  // cout << "p + t" <<  + p << endl;
  // cout << "p + q" << p + q << endl;
  // cout << "p fix order " << endl;
  // p.fix_order();
  // cout << "q fix order " << endl;
  // q.fix_order();
  // cout << "p + q" << p + q << endl;
  return true;
}

bool test_sub_poly(bool debug = false){
if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  // double coefs1[] = {8.0,5.0,6.0,0.0,4.0,10.0};
  // double coefs2[] = {4.0,12.0,-3.0,2.0, 5.0, 10.0,0.0,0.0};
   double coefs1[] = {0.0,0.0,6.0,0.0,0.0,0.0};
   double coefs2[] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,13.0};
  Poly p(coefs1, 5);
  Term t(3,4);
  Poly q(coefs2, 8);
  // cout << "p: " << p << endl;
  // // cout << "t: " << t << endl;
  // cout << "-q " << endl;
  // cout << -q << endl;
  cout << "p is " << p << endl; 
  cout << "q is " << q << endl;
  cout << "q + (-p) " << q + (-p) << endl; 

  return true;
}

bool test_multiplication(bool debug = false){
if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  double coefs1[] = {8.0,5.0};
  //(5X^1 + 8X^0) * 3X^4  =  15X^5 + 24X^54
  Poly p(coefs1, 4);
  Term t(3,4);
  //cout << p << endl;
 // cout << t << endl;
  cout << "p * t" << p * t << endl;
  return true; 
}

bool test_ttimesp(bool debug = false){
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------MULTIPLICATION----------------------" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "----------------------------------------------" << endl;
  double coefs3[]= {-1.0,9.0,-2.0,0.0,0.0,-1.0,5.0,0.0,-8.0,9.0,10.0};
  double coefs4[] = {10.0,-3.0,-7.0,5.0};
  Poly a(coefs3,10);
  Poly b(coefs4,3);
  cout << "a * b  " << a * b << endl; 
  // double coefs1[] = {8.0,9.0};
  // double coefs2[] = {9.0,0.0};
  // + 10.0X^10 + 9.0X^9 -8.0X^8 + 0.0X^7 + 5.0X^6 -1.0X^5 + 0.0X^4 + 0.0X^3 -2.0X^2 + 9.0X^1 -1.0
  //+ 5.0X^3 -7.0X^2 -3.0X^1 + 10.0
  // Poly p(coefs1, 1);
  // Poly q(coefs2,1);
  // Term t(0,0);  
  // cout << "p*t " << p * t << endl;
  // // cout << "p: " << p << endl;
  // // cout << "q: " << q << endl;
  // // //5X^1 + 8X^0   *    6X^2 + 4X^1 + 9X^0=    30X^3 + 20X^2 + 45X^1 + 48X^2 + 32X^1 + 72X^0
  // cout << "p * q = " << p * q << endl;
  cout << "end. didnt crash " << endl;
  return true; 
}
TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
  EXPECT_EQ(1, test_add_poly(false));
  EXPECT_EQ(1, test_sub_poly(false));
  EXPECT_EQ(1, test_multiplication(false));
  EXPECT_EQ(1, test_ttimesp(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


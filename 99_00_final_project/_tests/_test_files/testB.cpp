#include "gtest/gtest.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/coord_translation/coord_translation.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <SFML/Graphics.hpp>
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
    
        // ShuntingYard sy(x);
        // Queue<Token*> p = sy.postfix();
        // RPN rpN(p);
        // // sf::Vector2f domain = graph_info->get_Domain();
        // sf::Vector2f domain = graph_info->_domain;
        // cout <<"   plot(): domain: (" << domain.x << ", ";
        // cout << domain.y <<")"<< endl;
        // double numOfPoints = graph_info->get_Num_of_Points();
        // double it = (domain.y - domain.x) / numOfPoints;
  }
  Graph_info*g= new Graph_info();
  cout << g->_equation << endl;
  cout << g->_points << endl;
  Coord_translation coord_translator(g);
          sf::Vector2f points;
          cout << g->_domain.x << endl;
        cout << "hi " << endl;
            points.x = -5;
            points.y = 0;
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            points.x = 5;
            points.y = 0; 
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            points.x = 0; 
            points.y = 0;
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
            g->_domain.x = -10;
            g->_domain.y = 0; 
             points.x = -2;
            points.y = 0;
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            points.x = -10;
            points.y = 0;
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            points.x = -5;
            points.y = 0; 
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
            points.x = 0; 
            points.y = 0;
            points = coord_translator.translate(points);
            cout << points.x << ", " << points.y << endl;
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


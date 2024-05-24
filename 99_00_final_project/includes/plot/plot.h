#ifndef PLOT_H
#define PLOT_H
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"
#include "../token/token.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../token/function.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../queue/MyQueue.h"
#include "../graph_info/graph_info.h"
#include "../coord_translation/coord_translation.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

class Plot{
    public:
    Plot(Graph_info*&g, Coord_translation* c):graph_info(g), coord_translator(c){
        
    }
    
    vector<sf::Vector2f> operator()(){
        coordinates.clear();
        string eq = graph_info->_equation;    //gets eq
        ShuntingYard sy(eq);
        Queue<Token*> p = sy.postfix();
        RPN rpN(p);
        double numOfPoints = graph_info->_points;   //num of points
        double it = (abs(graph_info->_domain.y - graph_info->_domain.x)) / numOfPoints;   //num of iterations
        for (double i = graph_info->_domain.x; i <= graph_info->_domain.y; i+=it){
            points = sf::Vector2f(i,rpN(i));    //gets cartesian coordinates 
            points = coord_translator->translate(points);   //gets screen coordinates 
            coordinates.push_back(points);      //pushes into vector of screen coords
        }
        return coordinates; 
    }
    
    private:
    sf::Vector2f points;
    vector<sf::Vector2f> coordinates;
    Graph_info* graph_info;
    Coord_translation* coord_translator;
    sf::Vector2f d;
    sf::Vector2f o;
};

#endif
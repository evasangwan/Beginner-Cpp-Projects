#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <SFML/Graphics.hpp>
#include "../random.h"
#include "../constants.h"
#include <iostream>
#include <vector>
using namespace std;

struct Graph_info{
    Graph_info(){
        yaxis = sf::Vector2f(560,400);
        xaxis = sf::Vector2f(560,400);
        _domain = sf::Vector2f(-5,5);
        _equation = "tan(x)";
        _points = 300;
        double x = WORK_PANEL;
        double y = SCREEN_HEIGHT;
        _window_dimensions = sf::Vector2f(x,y);
    }

    sf::Vector2f _window_dimensions;
    sf::Vector2f yaxis;
    sf::Vector2f xaxis;
    sf::Vector2f _domain;
    double _points;
    string _equation;
};

#endif

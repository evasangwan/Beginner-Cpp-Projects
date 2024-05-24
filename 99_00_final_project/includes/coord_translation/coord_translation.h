#ifndef COORD_TRANSLATION_H
#define COORD_TRANSLATION_H
#include <SFML/Graphics.hpp>
#include "../graph_info/graph_info.h"
#include "../random.h"
#include "../constants.h"
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

class Coord_translation{
    public:
    Coord_translation(Graph_info* &G):g(G){

    }
    sf::Vector2f translate(sf::Vector2f points){
        //dimension: 1120 by 800
        //origin: 560 by 400
        points.x = g->yaxis.x + (points.x*(WORK_PANEL/(abs(g->_domain.y-g->_domain.x))));  
        points.y = g->xaxis.y - (points.y*(SCREEN_HEIGHT/(abs(g->_domain.y-g->_domain.x))));
        return points;
    }
    private:
    Graph_info* g;
};
#endif
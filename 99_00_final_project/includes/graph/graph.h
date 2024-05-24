#ifndef GRAPH_H
#define GRAPH_H
#include <SFML/Graphics.hpp>
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
#include "../system.h" 
#include "../random.h"
#include "../constants.h"
#include "../plot/plot.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Graph {
public:
    Graph() {
        rec2.setSize(sf::Vector2f(3, 2000));
        rec2.setOrigin(1.5, 1000);
        rec.setSize(sf::Vector2f(2000, 3));
        rec.setOrigin(1000, 1.5);
        rec2.setFillColor(sf::Color(138,138,253));    //yaxis
        rec.setFillColor(sf::Color(138,138,253));    //xaxis
        shape.setRadius(3);
        shape.setOrigin(1.5, 1.5);
        shape.setFillColor(sf::Color(185, 185, 255));
    }

    Graph(Graph_info* ptr) : g(ptr) {
        rec2.setSize(sf::Vector2f(3, 2000));
        rec2.setOrigin(1.5, 1000);
        rec.setSize(sf::Vector2f(2000, 3));
        rec.setOrigin(1000, 1.5);
        rec2.setFillColor(sf::Color(138,138,253));
        rec.setFillColor(sf::Color(138,138,253));
        shape.setRadius(3);
        shape.setOrigin(1.5, 1.5);
        shape.setFillColor(sf::Color(185, 185, 255));
    }
    void update(Graph_info* &ptr) {
        g = ptr;
        rec2.setPosition(g->yaxis.x, g->yaxis.y);
        rec.setPosition(g->xaxis.x, g->xaxis.y);
        Coord_translation* c = new Coord_translation(g);
        Plot p(g, c);
        std::vector<sf::Vector2f> coordinates = p();
        circles.clear();
      
        for (int i = 0; i < coordinates.size(); i++) {
            sf::Vector2f points = coordinates.at(i);
            shape.setPosition(points.x, points.y);
            circles.push_back(shape);
        }
       
    }

    void Draw(sf::RenderWindow& window) {
        window.draw(rec);
        window.draw(rec2);
        for (int i = 0; i < circles.size(); i++) {
            window.draw(circles[i]);
        }
    }

    ~Graph() {

    }

private:
    sf::CircleShape shape;
    sf::RectangleShape rec;
    sf::RectangleShape rec2;
    Graph_info* g;
    std::vector<sf::CircleShape> circles;
};

#endif

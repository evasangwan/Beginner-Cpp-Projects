#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "random.h"
#include "constants.h"
#include <iostream>
#include "plot/plot.h"
#include "graph/graph.h"
#include "graph_info/graph_info.h"

using namespace std;
class System{
    public:
    System();
    System(Graph_info *ptr);
    void Step(int command, Graph_info*  &g);
    void Draw(sf::RenderWindow& window);

private:
    Graph_info* g;
    Graph graph;
};

#endif
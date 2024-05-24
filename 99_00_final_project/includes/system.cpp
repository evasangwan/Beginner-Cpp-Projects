#include "random.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include "system.h"
#include "graph/graph.h"
#include "coord_translation/coord_translation.h"
#include "graph_info/graph_info.h"
#include <iostream>
#include <vector>
using namespace std;

System::System(){

}

System::System(Graph_info* ptr):g(ptr)
{
    graph.update(g);
}

void System::Step(int command, Graph_info* &g)
{
    if (command == 4){  //pan left
        g->_domain.x -= .1;
        g->_domain.y -= .1; 
        g->yaxis.x += .1*(WORK_PANEL/(abs(g->_domain.y-g->_domain.x)));
        graph.update(g);
    }

    if (command == 6){  //pan right
        g->_domain.x += 0.1; 
        g->_domain.y += 0.1; 
        g->yaxis.x -= .1*(WORK_PANEL/(abs(g->_domain.y-g->_domain.x)));
        graph.update(g);
    }

    if(command == 10){ //pan up  
        g->xaxis.y += .1*(WORK_PANEL/(abs(g->_domain.y-g->_domain.x)));
        graph.update(g);
    }

    if(command == 12){ //pan down 
        g->xaxis.y -= .1*(WORK_PANEL/(abs(g->_domain.y-g->_domain.x)));
        graph.update(g);
    }

    if(command == 14){ //zoom in 
        g->_domain.x *= .99;
        g->_domain.y *= .99;
        graph.update(g);
    }

    if(command == 16){ //zoom out 
        g->_domain.x /= .99;
        g->_domain.y /= .99;
        graph.update(g);
    }

    if (command == 18){
        g = new Graph_info();
        graph.update(g);
    }
    
    graph.update(g);
}

void System::Draw(sf::RenderWindow& window)
{
    window.clear();
    graph.Draw(window);
}

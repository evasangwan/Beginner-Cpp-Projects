#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
    //added
    void _history(const vector<string> &history);
    sf::Vector2f pos;
    double getHeight(){return _height;}
    // string getEq();
private:
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    float _left;
    float _width;
    //added
    bool dontadd = false;
    double _height;
};

#endif // SIDEBAR_H

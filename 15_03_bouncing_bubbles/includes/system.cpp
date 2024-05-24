#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>
#include <vector>
using namespace std;

System::System()
{
    for (int i = 1; i < 14; i++){
        Particle part(i*9,i);
        Random r;
        int xpos = 100;
        int ypos = 100;
        // the shape of the object, along with its velocity, acceleration,
        // position, etc. should be part of the individual object.
        part.shape.setPosition(sf::Vector2f(xpos, ypos));
        // vel = sf::Vector2f(r.Next(-5, 5), r.Next(-5, 5)); // random velocity
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        part.shape.setFillColor(sf::Color(r_, g_, b_));
        system.push_back(part);
    }
    // _shape = sf::CircleShape(60);
    // _shape.setPosition(sf::Vector2f(xpos+ 1, ypos+10));
    // _vel = sf::Vector2f(r.Next(-10, 20), r.Next(-10, 20)); // random velocity
    // // int r_ = r.Next(0, 255);
    // // int g_ = r.Next(0, 255);
    // // int b_ = r.Next(0, 255);
    // _shape.setFillColor(sf::Color::Magenta);
}

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{
    Random r;
    for (int i = 0; i <system.size(); i++){
        Particle &part = system.at(i);
        part.shape.move(part.vel);
        sf::Vector2f pos = part.shape.getPosition();
        float radius = part.shape.getRadius();
        if ((pos.x) >= WORK_PANEL - radius*2) 
            part.vel = sf::Vector2f(-1 *(part.vel.x), 1 * (part.vel.y));
            // int r_ = r.Next(0, 255);
            // int g_ = r.Next(0, 255);
            // int b_ = r.Next(0, 255);
            // part.shape.setFillColor(sf::Color(r_, g_, b_));
        if (pos.x <= 0)
            part.vel = sf::Vector2f(-1 * (part.vel.x), 1 * (part.vel.y));
            // part.shape.setFillColor(sf::Color(r_, g_, b_));
        if ((pos.y) >= SCREEN_HEIGHT - radius*2)
            part.vel = sf::Vector2f(1 * part.vel.x, -1 * (part.vel.y));
            // part.shape.setFillColor(sf::Color(r_, g_, b_));
        if (pos.y <= 0)
            part.vel = sf::Vector2f(1 * part.vel.x, -1 * (part.vel.y));
            // part.shape.setFillColor(sf::Color(r_, g_, b_));
        }
    // all this is the responsibility of the
    //  individual object:
    // //added
    // _shape.move(_vel);
    // sf::Vector2f _pos = _shape.getPosition();
    // if ((_pos.x) >= WORK_PANEL - 20)
    //     _vel = sf::Vector2f(-1 * _vel.x, 1 * _vel.y);
    // if (_pos.x <= 0)
    //     _vel = sf::Vector2f(-1 * _vel.x, 1 * _vel.y);
    // if ((_pos.y) >= SCREEN_HEIGHT - 20)
    //     _vel = sf::Vector2f(1 * _vel.x, -1 * _vel.y);
    // if (_pos.y <= 0)
    //     _vel = sf::Vector2f(1 * _vel.x, -1 * _vel.y);

}

void System::Draw(sf::RenderWindow& widnow)
{
    widnow.clear();
    for (int i = 0; i < system.size(); i++){
        Particle &part = system.at(i);
        widnow.draw(part.shape);
    }
    // widnow.display();
}

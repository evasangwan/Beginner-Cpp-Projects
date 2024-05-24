#include "random.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "system.h"
#include <iostream>
#include <vector>
using namespace std;

System::System()
{
    Random r;
    for (int i = 0; i <=20; i++){
    system.push_back(new Circle(i*2,i*3,r.Next(0,5),r.Next(0,5),i*5));
    system.push_back(new Triangle(i*2,5,r.Next(0,5),r.Next(0,5),i*4));
    system.push_back(new Square(i*6,i,r.Next(0,5),r.Next(0,5),i*6));
    system.push_back(new Rectangle(i*3,5,r.Next(0,5),r.Next(0,5),i,i*2));
    }
}


void System::Step(int command)
{
    Random r;
    for (int i = 0; i < system.size(); i++)
    {
        Particle *part = system.at(i);
        part->Step(command);
    }
}

void System::Draw(sf::RenderWindow& window)
{
    window.clear();
    for (int i = 0; i < system.size(); i++)
    {
        Particle *part = system.at(i);
        part->Draw(window);
    }
}

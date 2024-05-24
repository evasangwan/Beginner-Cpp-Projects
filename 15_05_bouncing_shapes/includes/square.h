#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>
#include <vector>

class Square : public Particle {
public:
    Square(double x, double y, double xvel, double yvel, double sideLength)
    :Particle(x, y, xvel, yvel), rotationAngle(0)
{
        // shape = new sf::RectangleShape(sideLength);
        // // shape->setPointCount(3);
        // shape->setPosition(getPos());
        // vel = getVel();
        // // shape->setSize(sf::Vector2f(sideLength, sideLength));
        // Random r;
        // int r_ = r.Next(0, 255);
        // int g_ = r.Next(0, 255);
        // int b_ = r.Next(0, 255);
        // shape.setFillColor(sf::Color(r_, g_, b_));
        // // vel = sf::Vector2f(xvel/2, yvel/2); 
        shape = new sf::CircleShape(sideLength);
        shape->setPointCount(4);
        shape->setPosition(getPos());
        vel = getVel();
        // shape.setPointCount(3);
        // shape.setRadius(side);
        Random r;
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        shape->setFillColor(sf::Color(r_, g_, b_));
    }

//   void Step(int command) override {
//        shape->move(vel);
//        rotationAngle+=2;
//         shape->setRotation(rotationAngle);
//          sf::Vector2f size = shape->getSize();  
//         sf::Vector2f pos = shape->getPosition();
//         if (pos.x >= WORK_PANEL - size.x)
//             vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
//         if (pos.x <= 0)
//             vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
//         if (pos.y >= SCREEN_HEIGHT - size.y)
//             vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
//         if (pos.y <= 0)
//             vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
//     }
   void Step(int command) override {
        shape->move(vel);
        rotationAngle+=2;
        shape->setRotation(rotationAngle);
        sf::Vector2f pos = shape->getPosition();
        float radius = shape->getRadius();
        if (pos.x >= WORK_PANEL - radius * 2)
            vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
        if (pos.x <= 0)
            vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
        if (pos.y >= SCREEN_HEIGHT - radius * 2)
            vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
        if (pos.y <= 0)
            vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
    }


    void Draw(sf::RenderWindow& window) override {
        window.draw(*shape);
    }
    virtual ~Square() override{
        delete shape;
    }


private:
    sf::CircleShape* shape;
    sf::Vector2f vel;
    double rotationAngle;
};

#endif

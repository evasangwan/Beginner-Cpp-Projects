#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>
#include <vector>

class Rectangle : public Particle {
public:
    Rectangle(double x, double y, double xvel, double yvel, double width, double length)
        : Particle(x, y, xvel, yvel), rotationAngle(0), _length(length), _width(width)
    {
        shape = new sf::RectangleShape(sf::Vector2f(_width,_length));
        shape->setPosition(getPos());
        vel = getVel();
        // shape.setSize(sf::Vector2f(width, height+20));
        Random r;
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        shape->setFillColor(sf::Color(r_, g_, b_));
        // vel = sf::Vector2f(xvel/2, yvel/2);
    }

    // void Step(int command) override {
    //     shape->move(vel);
    //     rotationAngle+=2;
    //     shape->setRotation(rotationAngle);
    //     sf::Vector2f pos = shape.getPosition();
    //     sf::Vector2f size = shape.getSize();
    //     if (pos.x >= WORK_PANEL - size.x)
    //         vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
    //     if (pos.x <= 0)
    //         vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
    //     if (pos.y >= SCREEN_HEIGHT - size.y)
    //         vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
    //     if (pos.y <= 0)
    //         vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
    // }
      void Step(int command) override {
        shape->move(vel);
        sf::Vector2f pos = shape->getPosition();
        rotationAngle+=2;
        shape->setRotation(rotationAngle);
        // float radius = shape->getRadius();
        if (pos.x >= WORK_PANEL - _length)
            vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
        if (pos.x <= 0)
            vel = sf::Vector2f(-1 * (vel.x), 1 * (vel.y));
        if (pos.y >= SCREEN_HEIGHT - _length)
            vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
        if (pos.y <= 0)
            vel = sf::Vector2f(1 * vel.x, -1 * (vel.y));
    }

    void Draw(sf::RenderWindow& window) override {
        window.draw(*shape);
    }
    virtual ~Rectangle() override{
        delete shape;
    }


private:
    sf::RectangleShape* shape;
    sf::Vector2f vel;
    double rotationAngle;
    double _length;
    double _width;
};

#endif

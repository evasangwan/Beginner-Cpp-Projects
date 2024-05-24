#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>
#include "system.h"
#include "random.h"
#include "constants.h"
#include <iostream>
#include <vector>

class Triangle : public Particle{
public:
    Triangle(double x, double y, double xvel, double yvel, double side)
        : Particle(x, y, xvel, yvel), rotationAngle(0.0)
    {
        shape = new sf::CircleShape(side);
        shape->setPointCount(3);
        shape->setPosition(getPos());
        vel = getVel();
        // shape.setPointCount(3);
        // shape.setRadius(side);
        Random r;
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        shape->setFillColor(sf::Color(r_, g_, b_));
        // vel = sf::Vector2f(xvel/2, yvel/2); 
    }

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
    virtual ~Triangle() override{
        delete shape;
    }


private:
    double rotationAngle;
    sf::CircleShape* shape;
    sf::Vector2f vel;
};

#endif

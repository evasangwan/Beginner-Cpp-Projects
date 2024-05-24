#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "system.h" 
#include "random.h"
#include "constants.h"
#include <iostream>
#include <vector>

class Circle : public Particle {
public:
    Circle(double x, double y, double xvel, double yvel, double radius)
        : Particle(x, y, xvel, yvel)
    {
        shape = new sf::CircleShape(radius);
        shape->setPosition(getPos());
        vel = getVel();
        // vel = sf::Vector2f(xvel/2, yvel/2); 
        // shape->setPosition(sf::Vector2f(x,y));
        // shape.setRadius(radius);
        Random r;
        int r_ = r.Next(0, 255);
        int g_ = r.Next(0, 255);
        int b_ = r.Next(0, 255);
        shape->setFillColor(sf::Color(r_, g_, b_));
        // vel = sf::Vector2f(xvel/2, yvel/2); 
    }
    void Step(int command) override {
        shape->move(vel);
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

    virtual ~Circle() override{
        delete shape;
    }

private:
    sf::CircleShape* shape;
    sf::Vector2f vel;
};

#endif

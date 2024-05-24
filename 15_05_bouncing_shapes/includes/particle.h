#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "random.h"
#include "constants.h"
#include <iostream>
using namespace std;

 class Particle{
        public:
            Particle(double x, double y, double xvel, double yvel)
            {
                vel = sf::Vector2f(xvel, yvel);
                pos = sf::Vector2f(x, y);
            }

            virtual ~Particle(){

            }

            virtual void Step(int command)
            {
              
            }
            sf::Vector2f getVel(){
                return vel;
            }
            sf::Vector2f getPos(){
                return pos;
            }
            // virtual void move(){
            //     pos = sf::Vector2f(pos.x + vel.x, pos.y+vel.y);
            //     particle.setPosition(pos);
            // }
            virtual void Draw(sf::RenderWindow& window)
            {
                // widnow.draw(particle);
                //cout<<pos.x<<", "<<pos.y<<endl;
            }

        private:
            // double x_coord;
            // double y_coord;
            // // double x_velocity;
            // // double y_velocity;
            // // double _mass;
            // double radius;
            // int _color;
            // sf::CircleShape particle;
            sf::Vector2f vel;
            sf::Vector2f pos;
            
            // sf::Color color;
        };

#endif
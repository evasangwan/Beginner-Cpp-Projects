#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
class System{
    public:
    class Particle{
        public:
            Particle(){
                shape = sf::CircleShape(10);
                vel = sf::Vector2f(-5,5);
            }
            Particle(int radius, int velocity){
                shape = sf::CircleShape(radius);
                vel = sf::Vector2f(velocity,velocity-2);
            }

            sf::CircleShape shape;
            sf::Vector2f vel;
    };
    System();
    void Step(int command);
    void Draw(sf::RenderWindow& widnow);
    // void Draw(vector<Particle> system);
private:
   vector<Particle> system;
    // sf::CircleShape shape;
    // // //added 
    // // sf::CircleShape _shape;
    // sf::Vector2f vel;
    // // //added 
    // // sf::Vector2f _vel;
};


#endif // SYSTEM_H

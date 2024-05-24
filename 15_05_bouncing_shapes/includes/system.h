#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "random.h"
#include "constants.h"
#include <iostream>
#include "particle.h"

using namespace std;
class System{
    public:
    System();
    void Step(int command);
    void Draw(sf::RenderWindow& window);

private:
    vector<Particle*> system;
};

#endif
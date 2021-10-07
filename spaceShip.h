#ifndef __SPACESHIP__
#define __SPACESHIP__

#include "space.h"

class spaceShip : public space
{
    //attributes
private:
    int speed;             //  speed of the spaceShip in number of cells covered in a single cycle
    int reinforcementRate; //  rate of reinforcement for the spaceShip

    //functions
public:
    spaceShip();                                    //  default constructor
    spaceShip(int s, int r, int x, int y, int bno); //  parameterized constructor
    ~spaceShip() {}                                 //  default destructor

    location nextMove();                                        //  randomly chooses a direction and returns target location
    bool isSpaceShip() { return true; }                         //  overridden spaceShip identifier function
    void setSpeed(int sp) { speed = sp; }                       //  setter function for speed
    void setReinforcementRate(int r) { reinforcementRate = r; } // setter function for reinforcement rate
    int getSpeed() { return speed; }                            // getter function for speed
    int getReinforcementRate() { return reinforcementRate; }    //  getter function for reinforcementRate
};

#endif
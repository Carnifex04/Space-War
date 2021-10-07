#ifndef __MOTHERSHIP__
#define __MOTHERSHIP__

#include "spaceShip.h"

class motherShip : public spaceShip
{
private:
    int starShipsDestroyed;

    //functions
public:
    motherShip();                                    //  Default motherShip constructor
    motherShip(int s, int r, int x, int y, int bno); //  motherShip constructor to initialize attributes
    ~motherShip() {}                                 //  Default motherShip destructor

    bool isMotherShip() { return true; } //  overridden motherShip identifier function
    void setLocation(int x, int y);      //  Reset location attributes for the motherShip object
    void incStarShipDestroyed()
    {
        ++starShipsDestroyed;
    } //  Increments starShipsDestroyed attribute
};

#endif
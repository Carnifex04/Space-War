#ifndef __STARSHIP__
#define __STARSHIP__

#include "spaceShip.h"

class starShip : public spaceShip
{
    public:
    starShip () {} //  Default starShip constructor
    starShip (int s, int r, int x, int y, int bno) ; //  starShip constructor to initialize attributes
    ~starShip () {}  //  Default starShip destructor

    bool isStarShip () { return true ; }  //  overridden starShip identifier function
    void setLocation (int x, int y) ; //  Reset location for starShip object
};

#endif

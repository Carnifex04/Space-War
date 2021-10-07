#ifndef __SPACEDEBRIS__
#define __SPACEDEBRIS__

#include "space.h"
class spaceDebris : public space
{
    //functions
    public:
    spaceDebris () ; //  default constructor
    spaceDebris (int x, int y, int bno) ;  //  parameterized constructor
    ~spaceDebris () {} //  default destructor

    bool isSpaceDebris () { return true ; }  //  overridden spaceDebris identifier function
};

#endif
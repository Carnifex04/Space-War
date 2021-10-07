#include "spaceDebris.h"


/*
*
* Argument:
* Return:
* Description:
      default constructor for spaceDebris object
*
*/

spaceDebris::spaceDebris () {
}


/*
*
* Argument: coordinates for the position of the spaceDebris along with parameters for base space class
* Return:
* Description:
       parameterized constructor for spaceDebris object
*
*/

spaceDebris::spaceDebris (int x, int y, int bno) : space( x, y, bno) {
}

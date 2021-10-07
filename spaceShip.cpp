#include "spaceShip.h"


/*
*
* Argument:
* Return:
* Description:
      Default constructor for spaceShip object
*
*/

spaceShip::spaceShip () {
  speed = 1 ;
  reinforcementRate = 2 ;
}


/*
*
* Argument:
* Return:
* Description:
      parameterized constructor for spaceShip object
*
*/

spaceShip::spaceShip (int s, int r, int x, int y, int bno) : space (x, y, bno) {
  speed = s ;
  reinforcementRate = r ;
}

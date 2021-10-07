#include "starShip.h"


/*
*
* Argument:
* Return:
* Description:
      parameterized constructor for starShip object
*
*/

starShip::starShip (int s, int r, int x, int y, int bno) :  spaceShip (s, r, x, y, bno) {

}


/*
*
* Argument:
* Return:
* Description:
      Reset location for starShip object
*
*/

void starShip::setLocation (int x, int y) {
  loc.setX (x) ;
  loc.setY (y) ;
}

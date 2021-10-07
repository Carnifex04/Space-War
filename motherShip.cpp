#include "motherShip.h"

/*
* Description:
      constructor for motherShip object
*
*/

motherShip::motherShip()
{
}

/*
*
* Argument: coordinates for the position of the motherShip along with parameters for base spaceShip class
* Description:
       Default constructor for motherShip object
*
*/

motherShip::motherShip(int s, int r, int x, int y, int bno) : spaceShip(s, r, x, y, bno)
{
  starShipsDestroyed = 0;
}

/*
* Description:
      Reset location for motherShip object
*
*/

void motherShip::setLocation(int x, int y)
{
  loc.setX(x);
  loc.setY(y);
}

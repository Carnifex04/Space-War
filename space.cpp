#include <iostream>
#include "space.h"
using namespace std;

/*

* Description:
      Default constructor for location object
*
*/

location::location()
{
      x = -1;
      y = -1;
}

/*
*
* Argument:integer row number, integer column number
* Description:
      parameterized constructor for location object
*
*/

location::location(int i, int j)
{
      x = i;
      y = j;
}

/*
*
* Argument: location element
* Return: bool
* Description:
      returns the == comparison between two Location elements
*
*/

bool location::operator==(location r)
{

      return ((x == r.getX()) && (y == r.getY()));
}

/*
*
* Argument: location element
* Return: bool
* Description:
      returns the == comparison between two Location pointer elements
*
*/

bool location::operator==(location *r)
{

      return ((x == r->getX()) && (y == r->getY()));
}

/*
*
* Argument:
* Return:
* Description:
      Default constructor for space object
*
*/

space::space()
{
      spawn = 0;
      loc.setX(-1);
      loc.setY(-1);
}

/*
*
* Argument: integer row number, integer column number, integer born on (iteration count)
* Return:
* Description:
      parameterized constructor for space object
*
*/

space::space(int x, int y, int bno)
{
      spawn = bno;
      loc.setX(x);
      loc.setY(y);
}

/*
*
* Argument:
* Return:
* Description:
      default constructor for vacuum object
*
*/

vacuum::vacuum()
{
}

/*
*
* Argument: coordinates for the position of the vacuum along with parameters for vacuum space class
* Return:
* Description:
       parameterized constructor for vacuum object
*
*/

vacuum::vacuum(int x, int y, int bno) : space(x, y, bno)
{
}

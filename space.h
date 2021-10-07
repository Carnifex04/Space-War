#ifndef __SPACE__
#define __SPACE__

//  Class name	: Location
//  Description	:  Class implements a location class to hold the location of objects in the simulation (row number, column number)

class location
{
  //attributes
private:
  int x; // row number
  int y; // column number

  //function
public:
  location();             //  default constructor
  location(int i, int j); //  parameterized constructor
  ~location() {}          //  default destructor

  int getX() { return x; }    //  getter function
  int getY() { return y; }    //  getter function
  void setX(int i) { x = i; } //  setter function for X
  void setY(int j) { y = j; } //  setter function for Y

  bool operator==(location r);  //  overloaded operator
  bool operator==(location *r); //  overloaded operator
};

// Class name	: space
// Description: Class implements a space class that acts as an abstract class for the simulation
//              All other classes inherit from this space class

class space
{
  //attributes
private:
  int spawn; // holds the start cycle for the object (initialized with the iteration number at which this object is created; defaults to 0)

public:
  location loc; //  holds the current location for the object

  //functions
public:
  space();                          //  default space constructor
  space(int x, int y, int bno = 0); //  parameterized constructor with initialization for Location
  ~space() {}                       // default destructor

  virtual bool isVacuum() { return false; }      //  Abstract function to be overridden by derived classes. Returns true when overridden by vacuum.
  virtual bool isSpaceDebris() { return false; } //  Abstract function to be overridden by derived classes. Returns true when overridden by rock.
  virtual bool isSpaceShip() { return false; }   //  Abstract function to be overridden by derived classes. Returns true when overridden by fish.
  virtual bool isStarShip() { return false; }    //  Abstract function to be overridden by derived classes. Returns true when overridden by salmon.
  virtual bool isMotherShip() { return false; }  //  Abstract function to be overridden by derived classes. Returns true when overridden by shark.
  virtual space *getPointer() { return this; }   //  Abstract function to be overridden by derived classes. Returns a pointer to this object.

  int getSpawnCycle() { return spawn; } //  getter function for spawn
};

/**
 * Class name	: vacuum
 * Description	:  Class implements a vacuum class to simulate vacuum in the simulation
 */

class vacuum : public space
{
  //functions
public:
  vacuum();                      //  default constructor
  vacuum(int x, int y, int bno); //  parameterized constructor
  ~vacuum() {}                   //  default destructor

  bool isVacuum() { return true; }     //  overridden vacuum identifier function
  space *getPointer() { return this; } //  overridden getPointer function. Returns pointer to vacuum object.
};

#endif
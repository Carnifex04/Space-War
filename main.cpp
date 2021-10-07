
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include "space.h"
#include "spaceShip.h"
#include "starShip.h"
#include "motherShip.h"
#include "spaceDebris.h"
#include "display.h"

/**
 * Class name	: simulation
 * Description	:  Class implements a simulation class to handle the simulation
 */

class simulation
{
  //attributes
private:
  //  initialized simulation attributes
  int nRows;                    //  number of rows in simulation field
  int nColumns;                 //  number of columns in simulation field
  int nCycles;                  //  cycles/time the simulation has to run for
  float motherShipPercentage;   //  percentage of initial cells for motherShips
  float starShipPercentage;     //  percentage of initial cells for starShips
  float spaceDebrisPercentage;  //  percentage of initial cells for spaceDebris
  int maxMotherShipAge;         //  maximum age for motherShips
  int maxStarShipAge;           //  maximum age for starShips
  int maxSpaceDebrisAge;        //  maximum age for spaceDebris
  int spaceShip_To_spaceDebris; //  number of spaceShips to corrode before a spaceDebris is formed
  int maxMotherShipSpeed;       //  speed for motherShips
  int maxStarShipSpeed;         //  speed for starShips
  int starShipRRate;            //  reinforcement rate for starShips
  int motherShipRRate;          //  reinforcement rate for motherShips

  //  calculated attributes
  int numStarShip;           //  number of starShips
  int numMotherShip;         //  number of motherShips
  int numSpaceDebris;        //  number of spaceDebris
  int numStarShipSpawn;      //  number of starShips Spawn
  int numMotherShipSpawn;    //  number of motherShips Spawn
  int numSpaceDebrisCreated; //  number of spaceDebris created
  int numStarShipCorroded;   //  number of starShips that corroded during the simulation
  int numMotherShipCorroded; //  number of motherShips that corroded during the simulation
  int numSpaceDebrisRemoved; //  number of spaceDebris that were removed from the simulation due to crossing its max age
  int numStarShipDestroyed;  //  number of starShips destroyed by motherShips
  int nCurrentCycle;         //  the current iteration (used to set Spawn on iteration for spaceShips. helps calculate age)

public:
  //  simulation environment and other objects
  std::vector<std::vector<std::vector<space *>>> _space_; //  a 3 dimensional platform for the simulation to run on.
                                                          //  3rd dimension enables cases where more than 1 spaceShip falls on a single cell (2 starShips or 2 motherShips)
  std::vector<std::vector<space *>> _space_row_;          //  the row vector that can be used to initialize the 3d space
  std::vector<space *> _space_cell_;                      //  a single cell representing a single cell on the 3d space

  std::vector<spaceDebris *> v_spaceDebris; //  spaceDebris vector to store all spaceDebris object
  std::vector<vacuum *> v_vacuum;           //  vacuum vector to store all vacuum objects
  std::vector<starShip *> v_starShips;      //  starShips vector to store all starShip objects
  std::vector<motherShip *> v_motherShips;  //  motherShips vector to store all motherShip objects

  //functions
public:
  simulation();                    //  default simulation constructor
  simulation(int m, int n, int c); //  parameterized constructor that sets dimensions for the simulation environment and number of cycles
  ~simulation() {}                 //  default simulation destructor

  int getNRows() { return nRows; }                                   //  getter function for nRows
  int getnColumns() { return nColumns; }                             // getter function for nColumns
  int getNCycles() { return nCycles; }                               //  getter function for nCycles
  float getmotherShipPercentage() { return motherShipPercentage; }   //  getter function for motherShipPercentage
  float getstarShipPercentage() { return starShipPercentage; }       //  getter function for starShipPercentage
  float getspaceDebrisPercentage() { return spaceDebrisPercentage; } //  getter function for spaceDebrisPercentage

  void setNRows(int n) { nRows = n; }                                       //  setter function for nRows
  void setnColumns(int n) { nColumns = n; }                                 //  setter function for nColumns
  void setCycles(int n) { nCycles = n; }                                    //  setter function for nCycles
  void setmotherShips(float f) { motherShipPercentage = f; }                //  setter function for motherShipPercentage
  void setstarShips(float f) { starShipPercentage = f; }                    //  setter function for starShipPercentage
  void setspaceDebris(float f) { spaceDebrisPercentage = f; }               //  setter function for spaceDebrisPercentage
  void setmaxMotherShipAge(int n) { maxMotherShipAge = n; }                 //  setter function for maxMotherShipAge
  void setmaxStarShipAge(int n) { maxStarShipAge = n; }                     //  setter function for maxStarShipAge
  void setmaxSpaceDebrisAge(int n) { maxSpaceDebrisAge = n; }               //  setter function for maxSpaceDebrisAge
  void setspaceShip_To_spaceDebris(int n) { spaceShip_To_spaceDebris = n; } //  setter function for spaceShip_To_spaceDebris
  void setmaxMotherShipSpeed(int n) { maxMotherShipSpeed = n; }             //  setter function for maxMotherShipSpeed
  void setmaxStarShipSpeed(int n) { maxStarShipSpeed = n; }                 //  setter function for maxStarShipSpeed
  void setstarShipRRate(int n) { starShipRRate = n; }                       //  setter function for starShipRRate
  void setmotherShipRRate(int n) { motherShipRRate = n; }                   //  setter function for motherShipRRate

  int generate();                           //  generates the simulation field (the space of nRows X nColumns cells)
  int initialize();                         //  initializes the space with required number of motherShips, starShip and spaceDebris
  int simulate();                           //  starts and simulates the set environment for the set number of cycles
  int getPossibleMoves(int i, int j);       //  checks for possible moves the spaceShip can take from its current position i, j
  void moveTo(int i, int j, location dest); //  moves spaceShip from i,j to dest location
  void reinforcement(location at);          //  reinforcement for spaceShip at locatio 'at'
  void corrodeToAge();                      //  kills off spaceShips and spaceDebris based on the set max age parameters
  // void calculateAttributes () ; //  calculates values for the calculated attributes

  std::string getStatus(); //  returns string with current status of the simulation's environment
  std::string toString();  //  returns the results for a completed simulation * To be run after simulate()
};

std::string int2str(int n);     //  function converts an integer value to a string
std::string num2char(int n);    //  function returns the string equivalent to the passed digit
unsigned int intFloor(float f); //  returns the integer floor value to passed floating point number

int main()
{
  Display hello;
  hello.welcomeText();

  simulation *sim1 = new simulation(5, 5, 2);

  std::cout << "\nGenerating Space War... ";

  sim1->generate();

  std::cout << "\nSpace War generated! " << std::endl;

  sim1->setstarShips(0.3);    //  set starShip percenetage
  sim1->setmotherShips(0.09); //  set motherShips percentage
  sim1->setspaceDebris(0.05); //  set spaceDebris percentage

  sim1->setmaxStarShipSpeed(1);
  sim1->setmaxMotherShipSpeed(1);

  std::cout << "\nInitializing Space War... ";

  sim1->initialize();

  std::cout << "\nThe War Begins! " << std::endl;

  std::cout << "\nSpace War running for " << sim1->getNCycles() << " iterations..." << std::endl;

  sim1->simulate();

  std::cout << "------------------" << std::endl;
  std::cout << "Final status : " << std::endl;
  std::cout << "------------------" << std::endl;

  std::cout << sim1->toString();
}

/*
*
* Argument:
* Return:
* Description:
      Default constructor for simulation object
*
*/

simulation::simulation()
{

  nRows = 10;
  nColumns = 10;
  nCycles = 100;
  motherShipPercentage = 0.05;
  starShipPercentage = 0.1;
  spaceDebrisPercentage = 0.07;
  maxMotherShipAge = 30;
  maxStarShipAge = 20;
  maxSpaceDebrisAge = 200;
  spaceShip_To_spaceDebris = 500;
  maxMotherShipSpeed = 1;
  maxStarShipSpeed = 1;
  starShipRRate = 8;
  motherShipRRate = 3;
  //  calculated attributes
  numStarShip = 0;
  numMotherShip = 0;
  numSpaceDebris = 0;
  numStarShipSpawn = 0;
  numMotherShipSpawn = 0;
  numSpaceDebrisCreated = 0;
  numStarShipCorroded = 0;
  numMotherShipCorroded = 0;
  numSpaceDebrisRemoved = 0;
  numStarShipDestroyed = 0;
  nCurrentCycle = 0;
}

/*
*
* Argument: integer, integer, integer
* Return:
* Description:
      parameterized constructor for simulation object
*
*/

simulation::simulation(int m, int n, int c)
{

  nRows = m;
  nColumns = n;
  nCycles = c;
  motherShipPercentage = 0.05;
  starShipPercentage = 0.1;
  spaceDebrisPercentage = 0.07;
  maxMotherShipAge = 30;
  maxStarShipAge = 20;
  maxSpaceDebrisAge = 200;
  spaceShip_To_spaceDebris = 500;
  maxMotherShipSpeed = 1;
  maxStarShipSpeed = 1;
  starShipRRate = 8;
  motherShipRRate = 3;
  //  calculated attributes
  numStarShip = 0;
  numMotherShip = 0;
  numSpaceDebris = 0;
  numStarShipSpawn = 0;
  numMotherShipSpawn = 0;
  numSpaceDebrisCreated = 0;
  numStarShipCorroded = 0;
  numMotherShipCorroded = 0;
  numSpaceDebrisRemoved = 0;
  numStarShipDestroyed = 0;
  nCurrentCycle = 0;
}

/*
*
* Argument:
* Return:
* Description:
      generates the simulation field (the space of nRows X nColumns cells)
*
*/

int simulation::generate()
{

  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nColumns; ++j)
    {
      v_vacuum.push_back(new vacuum(i, j, 0)); //  creates new vacuum object at location i,j with SpawnOn attribute 0
      _space_cell_.push_back(v_vacuum.back()->getPointer());
      _space_row_.push_back(_space_cell_);
      _space_cell_.clear();
    }
    _space_.push_back(_space_row_);
    _space_row_.clear();
  }

  return 1;
}

/*
*
* Argument:
* Return:
* Description:
      initializes the space with required number of motherShips, starShip and spaceDebris
*
*/

int simulation::initialize()
{

  int x, y, pos;

  for (int i = 1; i <= intFloor(float(nRows) * float(nColumns) * spaceDebrisPercentage); ++i)
  {

    srand(time(0));
    pos = rand() % v_vacuum.size();

    x = v_vacuum[pos]->loc.getX();
    y = v_vacuum[pos]->loc.getY();

    v_spaceDebris.push_back(new spaceDebris(x, y, 0));
    v_vacuum.erase(v_vacuum.begin() + pos);
    _space_[x][y].front() = v_spaceDebris.back()->getPointer();

    ++numSpaceDebris;
  }

  for (int i = 1; i <= intFloor(float(nRows) * float(nColumns) * starShipPercentage); ++i)
  {

    srand(time(0));
    pos = rand() % v_vacuum.size();

    x = v_vacuum[pos]->loc.getX();
    y = v_vacuum[pos]->loc.getY();

    v_starShips.push_back(new starShip(maxStarShipSpeed, starShipRRate, x, y, 0));
    v_vacuum.erase(v_vacuum.begin() + pos);
    _space_[x][y].front() = v_starShips.back()->getPointer();

    ++numStarShip;
  }

  for (int i = 1; i <= intFloor(float(nRows) * float(nColumns) * motherShipPercentage); ++i)
  {

    srand(time(0));
    pos = rand() % v_vacuum.size();

    x = v_vacuum[pos]->loc.getX();
    y = v_vacuum[pos]->loc.getY();

    v_motherShips.push_back(new motherShip(maxMotherShipSpeed, motherShipRRate, x, y, 0));
    v_vacuum.erase(v_vacuum.begin() + pos);
    _space_[x][y].front() = v_motherShips.back()->getPointer();

    ++numMotherShip;
  }

  return 1;
}

/*
*
* Argument:
* Return:
* Description:
      starts and simulates the set environment for the set number of cycles
*
*/

int simulation::simulate()
{

  location l;
  int ch;

  for (int p = 0; p < nCycles; ++p)
  {

    nCurrentCycle = p + 1;

    for (int i = 0; i < nRows; ++i)
    {
      for (int j = 0; j < nColumns; ++j)
      {

        if (_space_[i][j].front()->isSpaceShip())
        {

          int speed;
          if (_space_[i][j].front()->isStarShip())
            speed = maxStarShipSpeed;
          else if (_space_[i][j].front()->isMotherShip())
            speed = maxMotherShipSpeed;

          for (int s = 0; s < speed; ++s)
          {

            int ch = getPossibleMoves(i, j);

            if (ch >= 0)
            {

              if (ch == 0)
              {
                l.setX(i - 1);
                l.setY(j);
              }
              else if (ch == 1)
              {
                l.setX(i);
                l.setY(j + 1);
              }
              else if (ch == 2)
              {
                l.setX(i + 1);
                l.setY(j);
              }
              else if (ch == 3)
              {
                l.setX(i);
                l.setY(j - 1);
              }
            }
          }
        }
      }
    }

    corrodeToAge();
  }

  return 1;
}

/*
*
* Argument: integer, integer
* Return:
* Description:
      checks for possible moves the spaceShip can take from its current position i, j
*
*/

int simulation::getPossibleMoves(int i, int j)
{

  std::vector<int> v;

  if ((i == 0) && (j == 0))
  {

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);
  }
  else if ((i == 0) && (j > 0))
  {

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }
  else if ((i == 0) && (j == nColumns - 1))
  {

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }
  else if ((i > 0) && (j == 0))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);
  }
  else if ((i > 0) && (j == nColumns - 1))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }
  else if ((i == nRows - 1) && (j == 0))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);
  }
  else if ((i == nRows - 1) && (j > 0))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }
  else if ((i == nRows - 1) && (j == nColumns - 1))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }
  else if ((i > 0) && (j > 0))
  {

    if (!(_space_[i - 1][j].front()->isSpaceDebris()))
      v.push_back(0);

    if (!(_space_[i][j + 1].front()->isSpaceDebris()))
      v.push_back(1);

    if (!(_space_[i + 1][j].front()->isSpaceDebris()))
      v.push_back(2);

    if (!(_space_[i][j - 1].front()->isSpaceDebris()))
      v.push_back(3);
  }

  if (v.size())
  {
    srand(time(0));
    return v[rand() % v.size()];
  }
  else
    return -1;
}

/*
*
* Argument: integer, integer, location
* Return:
* Description:
      moves spaceShip from i,j to dest location
*
*/

void simulation::moveTo(int i, int j, location dest)
{

  if (_space_[dest.getX()][dest.getY()].front()->isVacuum())
  {
    if (_space_[i][j].front() == _space_[i][j].back())
    {
      space *temp = _space_[i][j].front();
      _space_[i][j].front() = _space_[dest.getX()][dest.getY()].front();
      _space_[dest.getX()][dest.getY()].front() = temp;

      _space_[i][j].front()->loc.setX(i);
      _space_[i][j].front()->loc.setY(j);
      _space_[dest.getX()][dest.getY()].front()->loc.setX(dest.getX());
      _space_[dest.getX()][dest.getY()].front()->loc.setY(dest.getY());
    }
    else
    {
      int p;

      for (p = 0; p < v_vacuum.size(); ++p)
      {
        if (v_vacuum[p]->loc == dest)
          break;
      }

      _space_[dest.getX()][dest.getY()].front() = _space_[i][j].front();
      _space_[dest.getX()][dest.getY()].front()->loc.setX(dest.getX());
      _space_[dest.getX()][dest.getY()].front()->loc.setY(dest.getY());
      _space_[i][j].erase(_space_[i][j].begin());
      v_vacuum.erase(v_vacuum.begin() + p);
    }
  }
  else if (_space_[i][j].front()->isStarShip())
  { //  source is a starShip

    if (_space_[dest.getX()][dest.getY()].front()->isMotherShip())
    { //  destination is a motherShip

      int p;

      for (p = 0; p < v_motherShips.size(); ++p)
      {
        if (v_motherShips[p]->loc == (new location(dest.getX(), dest.getY())))
          break;
      }

      v_motherShips[p]->incStarShipDestroyed();

      if (_space_[i][j].front() == _space_[i][j].back())
      { // source had only one starShip and destination is a motherShip

        for (p = 0; p < v_starShips.size(); ++p)
        {
          if (v_starShips[p]->loc == (new location(i, j)))
            break;
        }

        v_starShips.erase(v_starShips.begin() + p);
        --numStarShip;

        v_vacuum.push_back(new vacuum(i, j, 0));
        _space_[i][j].front() = (v_vacuum.back()->getPointer());
      }
      else
      { //  source had 2 starShips and the destination is a motherShip

        for (p = 0; p < v_starShips.size(); ++p)
        {
          if (v_starShips[p]->getPointer() == _space_[i][j].front())
            break;
        }

        v_starShips.erase(v_starShips.begin() + p);
        --numStarShip;
        _space_[i][j].erase(_space_[i][j].begin());
      }
    }
    else if (_space_[dest.getX()][dest.getY()].front()->isStarShip())
    { //  destination is also a starShip

      v_vacuum.push_back(new vacuum(i, j, 0));
      _space_[dest.getX()][dest.getY()].push_back(_space_[i][j].front()->getPointer());
      _space_[i][j].front() = (v_vacuum.back()->getPointer());

      reinforcement(dest);
    }
  }
  else if (_space_[i][j].front()->isMotherShip())
  { //  source is a motherShip

    if (_space_[dest.getX()][dest.getY()].front()->isStarShip())
    { //  destination is a starShip

      int p;

      for (p = 0; p < v_motherShips.size(); ++p)
      {
        if (v_motherShips[p]->loc == (new location(i, j)))
          break;
      }

      if (_space_[i][j].front() == _space_[i][j].back())
      { //  destination has only one starShip

        v_motherShips[p]->incStarShipDestroyed();

        for (p = 0; p < v_starShips.size(); ++p)
        {
          if (v_starShips[p]->getPointer() == _space_[i][j].front())
            break;
        }

        v_starShips.erase(v_starShips.begin() + p);
        --numStarShip;
      }
      else
      { //  destination has 2 starShips
        v_motherShips[p]->incStarShipDestroyed();
        v_motherShips[p]->incStarShipDestroyed();

        for (p = 0; p < v_starShips.size(); ++p)
        {
          if (v_starShips[p]->getPointer() == _space_[i][j].front())
            break;
        }

        v_starShips.erase(v_starShips.begin() + p);

        for (p = 0; p < v_starShips.size(); ++p)
        {
          if (v_starShips[p]->getPointer() == _space_[i][j].front())
            break;
        }

        v_starShips.erase(v_starShips.begin() + p);

        numStarShip -= 2;
      }

      v_vacuum.push_back(new vacuum(i, j, 0));
      _space_[dest.getX()][dest.getY()].front() = _space_[i][j].front();
      _space_[dest.getX()][dest.getY()].front()->loc.setX(dest.getX());
      _space_[dest.getX()][dest.getY()].front()->loc.setY(dest.getY());
      _space_[i][j].front() = (v_vacuum.back()->getPointer());
    }
    else if (_space_[dest.getX()][dest.getY()].front()->isMotherShip())
    { //  destination is also a motherShip

      v_vacuum.push_back(new vacuum(i, j, 0));
      _space_[dest.getX()][dest.getY()].push_back(_space_[i][j].front()->getPointer());
      _space_[i][j].front() = (v_vacuum.back()->getPointer());

      reinforcement(dest);
    }
  }
}

/*
*
* Argument: location
* Return:
* Description:
      reinforcement for spaceShip at location 'at'
*
*/

void simulation::reinforcement(location at)
{

  int rrate, pos, x, y;
  int on = nCurrentCycle;

  if (_space_[at.getX()][at.getY()].front()->isStarShip())
  {

    rrate = starShipRRate;

    while ((!v_vacuum.empty()) && rrate)
    {

      srand(time(0));
      pos = rand() % v_vacuum.size();

      x = v_vacuum[pos]->loc.getX();
      y = v_vacuum[pos]->loc.getY();

      v_starShips.push_back(new starShip(maxStarShipSpeed, starShipRRate, x, y, on));
      v_vacuum.erase(v_vacuum.begin() + pos);
      _space_[x][y].front() = v_starShips.back()->getPointer();

      ++numStarShip;
      ++numStarShipSpawn;
      --rrate;
    }
  }
  else if (_space_[at.getX()][at.getY()].front()->isStarShip())
  {

    rrate = motherShipRRate;

    while ((!v_vacuum.empty()) && rrate)
    {

      srand(time(0));
      pos = rand() % v_vacuum.size();

      x = v_vacuum[pos]->loc.getX();
      y = v_vacuum[pos]->loc.getY();

      v_motherShips.push_back(new motherShip(maxMotherShipSpeed, motherShipRRate, x, y, on));
      v_vacuum.erase(v_vacuum.begin() + pos);
      _space_[x][y].front() = v_motherShips.back()->getPointer();

      ++numMotherShip;
      ++numMotherShipSpawn;
      --rrate;
    }
  }
}

/*
*
* Argument:
* Return:
* Description:
      kills off spaceShips and spaceDebris based on the set max age parameters
*
*/

void simulation::corrodeToAge()
{

  for (int i = 0; i < v_starShips.size(); ++i)
  {

    if ((nCurrentCycle - v_starShips[i]->getSpawnCycle()) > maxStarShipAge)
    {

      ++numStarShipCorroded;

      if (numStarShipCorroded + numMotherShipCorroded == spaceShip_To_spaceDebris)
      {

        v_spaceDebris.push_back(new spaceDebris(v_starShips[i]->loc.getX(), v_starShips[i]->loc.getY(), nCurrentCycle));
        _space_[v_starShips[i]->loc.getX()][v_starShips[i]->loc.getY()].front() = v_spaceDebris.back()->getPointer();
        ++numSpaceDebrisCreated;
      }
      else
      {

        v_vacuum.push_back(new vacuum(v_starShips[i]->loc.getX(), v_starShips[i]->loc.getY(), 0));
        _space_[v_starShips[i]->loc.getX()][v_starShips[i]->loc.getY()].front() = v_vacuum.back()->getPointer();
      }

      v_starShips.erase(v_starShips.begin() + i);
    }
  }

  for (int i = 0; i < v_motherShips.size(); ++i)
  {

    if ((nCurrentCycle - v_motherShips[i]->getSpawnCycle()) > maxMotherShipAge)
    {

      ++numMotherShipCorroded;

      if (numStarShipCorroded + numMotherShipCorroded == spaceShip_To_spaceDebris)
      {

        v_spaceDebris.push_back(new spaceDebris(v_motherShips[i]->loc.getX(), v_motherShips[i]->loc.getY(), nCurrentCycle));
        _space_[v_motherShips[i]->loc.getX()][v_motherShips[i]->loc.getY()].front() = v_spaceDebris.back()->getPointer();
        ++numSpaceDebrisCreated;
      }
      else
      {

        v_vacuum.push_back(new vacuum(v_motherShips[i]->loc.getX(), v_motherShips[i]->loc.getY(), 0));
        _space_[v_motherShips[i]->loc.getX()][v_motherShips[i]->loc.getY()].front() = v_vacuum.back()->getPointer();
      }

      v_motherShips.erase(v_motherShips.begin() + i);
    }
  }

  for (int i = 0; i < v_spaceDebris.size(); ++i)
  {

    if ((nCurrentCycle - v_spaceDebris[i]->getSpawnCycle()) > maxSpaceDebrisAge)
    {

      ++numSpaceDebrisRemoved;

      v_vacuum.push_back(new vacuum(v_spaceDebris[i]->loc.getX(), v_spaceDebris[i]->loc.getY(), 0));
      _space_[v_spaceDebris[i]->loc.getX()][v_spaceDebris[i]->loc.getY()].front() = v_vacuum.back()->getPointer();

      v_spaceDebris.erase(v_spaceDebris.begin() + i);
    }
  }
}

/*
*
* Argument:
* Return:
* Description:
      returns string with current status of the simulation's environment
*
*/

std::string simulation::getStatus()
{

  std::string msg;

  msg = "";
  msg += "\nsimulation field : " + int2str(nRows) + "X" + int2str(nColumns);
  msg += "\nCycles : " + int2str(nCycles);
  msg += "\nField share : starShip - " + int2str(intFloor(float(nRows) * float(nColumns) * (starShipPercentage))) + "; motherShips - " + int2str(intFloor(float(nRows) * float(nColumns) * (motherShipPercentage))) + "; spaceDebris - " + int2str(intFloor(float(nRows) * float(nColumns) * (spaceDebrisPercentage)));
  msg += "\nInitialized with : ";

  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nColumns; ++j)
    {
      if (_space_[i][j].front()->isVacuum())
      {
        msg += "\n" + int2str(i) + "," + int2str(j) + ": vacuum [" + int2str(_space_[i][j].front()->loc.getX()) + "," + int2str(_space_[i][j].front()->loc.getY()) + ";" + int2str(_space_[i][j].front()->getSpawnCycle()) + "]";
      }
      else if (_space_[i][j].front()->isSpaceDebris())
      {
        msg += "\n" + int2str(i) + "," + int2str(j) + ": spaceDebris [" + int2str(_space_[i][j].front()->loc.getX()) + "," + int2str(_space_[i][j].front()->loc.getY()) + ";" + int2str(_space_[i][j].front()->getSpawnCycle()) + "]";
      }
      else if (_space_[i][j].front()->isStarShip())
      {
        msg += "\n" + int2str(i) + "," + int2str(j) + ": starShip [" + int2str(_space_[i][j].front()->loc.getX()) + "," + int2str(_space_[i][j].front()->loc.getY()) + ";" + int2str(_space_[i][j].front()->getSpawnCycle()) + "]";
      }
      else if (_space_[i][j].front()->isMotherShip())
      {
        msg += "\n" + int2str(i) + "," + int2str(j) + ": motherShip [" + int2str(_space_[i][j].front()->loc.getX()) + "," + int2str(_space_[i][j].front()->loc.getY()) + ";" + int2str(_space_[i][j].front()->getSpawnCycle()) + "]";
      }
      else
        msg += "\n" + int2str(i) + "," + int2str(j) + ": Error!!!\n";
    }
  }

  msg += "\nvacuum : " + int2str(v_vacuum.size()) + "; spaceDebris : " + int2str(v_spaceDebris.size()) + "; starShips : " + int2str(v_starShips.size()) + "; motherShips : " + int2str(v_motherShips.size()) + "\n";

  return msg;
}

/*
*
* Argument:
* Return:
* Description:
      returns the results for a completed simulation * To be run after simulate()
*
*/

std::string simulation::toString()
{

  std::string msg = "";

  msg += "\n motherShips left by the end of the simulation : " + int2str(numMotherShip);
  msg += "\n starShips left by the end of the simulation : " + int2str(numStarShip);
  msg += "\n spaceDebris left by the end of the simulation : " + int2str(numSpaceDebris);
  msg += "\n starShips destroyed by motherShips by the end of the simulation : " + int2str(numStarShipDestroyed);
  msg += "\n Do starShips and motherShips live with each other in the end or one loses? ";

  if (numStarShip > numMotherShip)
  {
    msg += "\n\t Yes, starShips and motherShips can live with each other. \n";
  }
  else
  {
    msg += "\n\t No, motherShips dominate starShips and starShips vanish. \n";
  }

  return msg;
}

/*
*
* Argument: int
* Return: string
* Description:
      returns the string equivalent of the passed integer digit
*
*/

std::string num2char(int n)
{
  if (n == 0)
    return "0";
  else if (n == 1)
    return "1";
  else if (n == 2)
    return "2";
  else if (n == 3)
    return "3";
  else if (n == 4)
    return "4";
  else if (n == 5)
    return "5";
  else if (n == 6)
    return "6";
  else if (n == 7)
    return "7";
  else if (n == 8)
    return "8";
  else if (n == 9)
    return "9";
  else
    return "-";
}

/*
*
* Argument: int
* Return: string
* Description:
      returns the string equivalent of the passed integer number
*
*/

std::string int2str(int n)
{

  std::string a;
  a = "";

  if (n > 0)
  {
    while (n)
    {

      a = num2char(n % 10) + a;
      n /= 10;
    }
  }
  else if (n < 0)
  {

    n = n * -1;

    while (n)
    {

      a = num2char(n % 10) + a;
      n /= 10;
    }

    a = "-" + a;
  }
  else if (n == 0)
    a = "0";
  return a;
}

/*
*
* Argument: float
* Return: unsigned int
* Description:
      returns the integer floor value to passed floating point number
*
*/

unsigned int intFloor(float f)
{
  for (unsigned int i = 1; i <= 1000000000; i++)
  {
    if (i > f)
      return i - 1;
  }
  return -1;
}

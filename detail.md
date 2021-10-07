A software simulation for a space-war. This simulation covers 4 elements, namely StarShip, MotherShip, SpaceDebris, and Vacuum. At the end of the simulation, we get all the statistics for major events during the lifecycle of the simulation and the final state of the war. The world was built around the following facts:


Facts:

·         Traffic:

          The World is filled with each element occupying a certain amount of given space.

·         Life Cycle:

i)        The War happens for a certain time period, ex: 10 or 1000000 units.

ii)       Every kind of ship will have a certain lifetime, after which it will corrode, which will constitute the space debris. 
          For example: when 10 StarShips corrode over time, they constitute one space unit of space debris.

iii)     After a certain amount of time, the space debris vanishes from the space.

iv)      When a certain spaceship is destroyed, it disappears from the space.

·        Movement:

i)        The SpaceShips can move in any random direction, i.e., Up, Down, Left, Right.

ii)       The SpaceShips cannot occupy spaces where there is space debris.

·        War Strategy:

i)        If a MotherShip and a StarShip arrive at the same position at the same time, then, MotherShip will destroy the StarShip, and the StarShip will disappear.

ii)       If two MotherShips arrive at the same position at the same time, they feel cornered and call reinforcements for help, which arrive at random positions in Space.

iii)     If two StarShips arrive at the same position at the same time, they call in reinforcements, which arrive at a random location in Space.


Results:

·         StarShips at the end of the war.

·         MotherShips at the end of the war.

·         SpaceDebris at the end of the war.

·         StarShips destroyed.

·         StarShips reinforcements called.

·         MotherShips reinforcements called.

·         SpaceDebris created after the start of the war.

·         StarShips corroded.

·         MotherShips corroded.

·         Who wins the war?

 
Details of the Project:

·        Class SpaceWar: Encapsulates all the classes and runs the simulation.

·        Class Space: Abstract class from which all other classes are derived.

a)       Class Vacuum - Derived from Class Space

(i)       Holds default cells in the space.

b)      Class SpaceDebris - Derived from Class Space

(i)      Class for space debris in space.

c)       Class SpaceShip - Derived from Class Space

(i)      Abstract class from which all other spaceships are derived.

(ii)    Holds properties common to spaceships but not space or space debris.

d)      Class MotherShip - Inherits from Class SpaceShip

(i)      Holds properties for MotherShips.

e)      Class StarShip - Inherits from Class SpaceShip

(i)      Holds properties for StarShips.
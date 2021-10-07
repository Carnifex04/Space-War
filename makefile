all: Simulation

Simulation: display.h main.cpp motherShip.cpp motherShip.h starShip.cpp starShip.h spaceShip.cpp spaceShip.h spaceDebris.cpp spaceDebris.h space.cpp space.h
	g++ -o Simulation main.cpp motherShip.cpp starShip.cpp spaceShip.cpp spaceDebris.cpp space.cpp

clear:
	rm -f Simulation
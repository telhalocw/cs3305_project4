# CS 2308 - Program 4
# makefile for TowerOfTerror program with two files:
# Queue.h,
# TowerOfTerror.cpp,
# PasswordDriver.cpp

a.out: TowerOfTerror.o 
	 g++ -std=gnu++0x TowerOfTerror.o 

TowerOfTerror.o: TowerOfTerror.cpp Queue.h
	 g++ -std=gnu++0x -c TowerOfTerror.cpp

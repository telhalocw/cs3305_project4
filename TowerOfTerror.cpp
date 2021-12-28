// File Name: TowerOfTerror.cpp
//
// Author: (David Hackenbracht)
// Date: 6/30/2020
// Assignment Number: 4
// CS 2308.501 Summer 2020
// Instructor: Dr. J Marcos Palacios
//
//  (This program simulates a ride scheduling system for a roller coaster)
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//***********************************************************
//readData: Takes data from input .txt file and reads it into a queue.
//          Returns an integer ride capacity determined from the .txt file and
//          the constant maximum capacity.
//rQueue is the queue
//oldCap is the capacity of the ride at 100% capacity
//percent is the percentage multiplier which helps determine new ride capacity
//***********************************************************

int readData(Queue &rQueue, int oldCap)
{
    ifstream fin;
    fin.open("reservations.txt");
    double percent; //percentage capacity at time
    //Read percent.
    fin >> percent;
    fin >> ws;

    string pName;
    int pSize;
    while(fin>>pName)
    {
        fin >> ws;
        fin >> pSize;
        rQueue.enqueue(pSize,pName);
    }
    return oldCap*percent;
}

//***********************************************************
//rideScheduler: Determines which guest groups can enter the ride based on
//          a predetermined capacity. Then displays party names and sizes
//          for each ride.
//rQueue is the queue
//newCap is the capacity of the ride at the percent determined by the .txt file
//rideCounter tracks the number of guests on any given ride
//numRides counts the total number of rides
//guestTotal is the overall number of guests over all rides
//***********************************************************
void rideScheduler(Queue &rQueue, int newCap)
{
    int rideCounter = 0;
    int numRides = 1;
    int guestTotal = 0;

    //Read info from the queue
    while(!(rQueue.isEmpty()))
    {
        //Dummy variables
        int value;
        string name;

        //Header
        cout << "Guest Information for Ride " << numRides << endl;
        cout << "****************************" << endl;

        //Adds parties to ride up to capacity, displays party info
        while((rQueue.getSizeAtFront() + rideCounter) <= newCap)
        {
            rQueue.dequeue(value,name);
            cout << name << ", party of " << value << endl;
            rideCounter += value;
            guestTotal += value;
            //To prevent a repeated listing of the final item in the queue
            if(rideCounter == newCap)
                break;

        }
        cout << "Total number of guests: " << rideCounter << endl << endl;
        numRides++;
        rideCounter = 0;
    }
    cout << "Overall number of Guests: " << guestTotal << endl;
    cout << "Overall number of Rides:  " << numRides -1 << endl;
}

int main()
{
    const int CAP = 50; //ride capacity
    Queue rQueue;

    //Both reads data from .txt file to queue and determines the new capacity
    int newCap = readData(rQueue,CAP);
    rideScheduler(rQueue,newCap);

    return 0;
}














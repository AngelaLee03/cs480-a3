/*
 * Filename: main.cpp
 *
 * CS480 Summer 2026
 * Programming Assignment #3 - Disk Arm Simulation
 *
 * Angela Lee (cssc3130)
 * Caitlin Corpus (cssc3114)
 *
 * Main driver for the disk arm scheduling simulation.
 * Generates a random sequence of cylinder requests and
 * runs each scheduling algorithm.
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "algorithms.h"

using namespace std;

/*
 * Main function:
 * Reads the sequence length from the command line,
 * generates random cylinder requests, and runs
 * each scheduling algorithm.
 */
int main(int argc, char* argv[])
{
    // Verify the correct command line usage
    if(argc != 2)
    {
        cout << "Usage: simarm <sequence length>" << endl;
        return 1;
    }

    // Convert the command line argument to integer
    int length = atoi(argv[1]);

    // Vector to store generated cylinder requests
    vector<int> requests;

    // Seed random number generator
    srand(time(NULL));

    // Generate random cylinder requests from 0 to 999
    for(int i = 0; i < length; i++)
    {
        requests.push_back(rand() % 1000);
    }

    // Run FCFS algorithm
    cout << "FCFS Distance: " << fcfs(requests) << endl;

    // Run SSTF algorithm
    cout << "SSTF Distance: " << sstf(requests) << endl;

    // Run Elevator algorithm
    cout << "Elevator Distance: " << elevator(requests) << endl;

    return 0;
}


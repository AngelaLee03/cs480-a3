/*
 * Filename: algorithms.cpp
 *
 * CS480 Summer 2026
 * Programming Assignment #3 - Disk Arm Simulation
 *
 * Angela Lee (cssc3130)
 * Caitlin Corpus (cssc3114)
 *
 * Contains the implementations of the disk arm
 * scheduling algorithms.
 */

#include <iostream>
#include <vector>
#include "algorithms.h"

using namespace std;

/*
 * First-Come, First-Served (FCFS)
 * Services requests in the order they were generated.
 */
int fcfs(const vector<int>& requests)
{
    // Disk arm starts at cylinder 0
    int current = 0;
    
    // Total distance traveled
    int distance = 0;

    // Visit each request in order
    for (size_t i = 0; i < requests.size(); i++)
    {
        distance += abs(requests[i] - current);
        current = requests[i];
    }
    
    return distance;
}

/*
 * Shortest Seek Time First (SSTF)
 */
int sstf(const vector<int>& requests)
{
    return 0;
}

/*
 * Elevator Algorithm (SCAN)
 */
int elevator(const vector<int>& requests)
{
    return 0;
}

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
#include <algorithm>
#include <climits>
#include <cmath>
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
 * Services closest request to current disk arm position
 */
int sstf(const vector<int>& requests)
{
    // Track which requests were serviced
    vector<bool> serviced(requests.size(), false);

    // Disk arm starts @ cylinder 0
    int curr = 0;

    // Total distance traveled
    int dist = 0;

    // Continue until all requests get serviced
    for (size_t count = 0; count < requests.size(); count++)
    {
        // Closest request found so far
        int closestIndex = -1;
        
        // Use closest request found so far
        int minDist = INT_MAX;

        // Find closest unserviced request
        for (size_t i = 0; i < requests.size(); i++)
        {
            if (!serviced[i])
            {
                int seek = abs(requests[i] - curr);

                if (seek < minDist)
                {
                    minDist = seek;
                    closestIndex = i;
                }
            }
        }
        // Service closest request
        serviced[closestIndex] = true;
        dist += minDist;
        curr = requests[closestIndex];
    }
    return dist;
}

/*
 * Elevator Algorithm (SCAN)
 * Services requests in ascending cylinder order
 */
int elevator(const vector<int>& requests)
{
    // Copy requests so original sequence is unchanged
    vector<int> sorted = requests;

    // Sort requests in ascending order
    sort(sorted.begin(), sorted.end());

    // Disk arm starts @ cylinder 0
    int curr = 0;

    // Total distance traveled
    int dist = 0;

    // Visit each of the requests in order
    for (size_t i = 0; i < sorted.size(); i++)
    {
        dist += abs(sorted[i] - curr);
        curr = sorted[i];
    }
    return dist;
}

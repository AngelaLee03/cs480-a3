/*
 * Filename: algorithms.h
 *
 * CS480 Summer 2026
 * Programming Assignment #3 - Disk Arm Simulation
 *
 * Angela Lee (cssc3130)
 * Caitlin Corpus (cssc3114)
 *   
 * Header file containing function prototypes for
 * the disk arm scheduling algorithms.
 *         
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

int fcfs(const std::vector<int>& requests);
int sstf(const std::vector<int>& requests);
int elevator(const std::vector<int>& requests);

#endif

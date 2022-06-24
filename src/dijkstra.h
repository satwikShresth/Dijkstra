/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *Date: 6/1/2022
 *Header File
 *
 *
 */
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include"heap.h"
#include"graph.h"
#include <assert.h>
#define MAX __INT_MAX__

//uses dijkstra algorithum to find the number of steps needed for each point on the graph
void dijkstra(graph* G, int start);

//updates the heap
void update(heap* H,int v, int distance);

//prints the array
void printArray(int dist[], int n);

#endif
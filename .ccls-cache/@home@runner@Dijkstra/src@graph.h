/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *Date: 6/1/2022
 *
 *header file
 *has all the prototype of functions present in the file
 *
 *
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

struct listNode{
    int destiantion;
    int weight;
    int value;
    struct listNode* next;
};
typedef struct listNode listNode;

struct list
{
   int src;
   struct listNode* head;
};
typedef struct list list;

struct graph
{
    struct list** array;
    int numberOfVertices;
};

typedef struct graph graph;

//creates a graph
graph* makeGraph(int size);

//inserts edges on the graph
void insertEdge(graph* G, int fromEdge, int toEdge, int weight);

//makes nodes for the edges
listNode* makeGraphNode(int toEdge, int weight);

//prints the graph
void printGraph(graph* G);

//frees the graph
void removeGraph(graph* G);

//frees the graphs
void removeGraphDataNodes(listNode* head);

#endif
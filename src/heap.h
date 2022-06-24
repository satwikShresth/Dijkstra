/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *header file
 *has all the prototype of functions present in the file
 *
 */
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>



struct heap{
	struct heapNode** data;
  int* position;
	int maxSize;
	int currentSize;
};
typedef struct heap heap;

struct heapNode{
	int v;
  int distance; 
};
typedef struct heapNode heapNode;

//Make a new Heap
heap* makeHeap(int capacity);

//Is the heap empty?
char empty(heap* H);

int pickSmallerChild(heap* H, int rightChild, int leftChild,int i);

// //Find value
// int findVal(heap* H,int value);

//What is the min?
heapNode* min(heap* H);

//Allocates memory and returns the node
heapNode* makeHeapNode(heap* H,int v, int distance);

//Delete the min
void deleteMin(heap* H);

//Get Index of Parent
int parent(int n);

//Get index of Left Child
int leftChild(int n);

//Get index of Right Child
int rightChild(int n);

//Swap i and j in heap
void swap(heap* H, int i, int j);

//Just to help debug
void printHeap(heap* H);

//Finds the minimum value in the heap
heapNode* minVal(heap* H);

void removeHeapData(heap* H);

void removeHeap(heap* H);

void downHeap(heap* H, int i);

#endif

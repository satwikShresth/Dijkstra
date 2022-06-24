/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *header file
 *has all the prototype of functions present in the file
 */
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>



struct heap{
	struct heapNode** data;
	int maxSize;
	int currentSize;
};
typedef struct heap heap;

struct heapNode{
	int pos;
  int value; 
};
typedef struct heapNode heapNode;

//Make a new Heap
heap* makenull(int capacity);

//Is the heap empty?
char empty(heap* H);

//Find value
int findVal(heap* H,int value);

//What is the min?
heapNode* min(heap* H);

//Delete the min
void deleteMin(heap* H);

//Insert a new value
void insert(int value, int freq, heap* H);

//Upheap a value at index i
void upheap(heap* H,int i);

//Get Index of Parent
int parent(int n);

int treeHeight(heapNode* current);

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

//finds the size of the array
int getArraySize(const char *filename);

//builds the huffman tree and put them into the heap
void buildHuffmanTree(heap* H);

//prints the value of encode with the percent present
void printEncodes(heap* heap,struct heap* H,int size);

//builds the heap required to encode the varibales using huffman tree
void buildHuffmanHeap(heap* H,heap* heap,int size, const char *filename);

//frees the tree when given the root
void removeTree(heapNode* current);

void removeHeapData(heap* H);

void removeHeap(heap* H);

#endif

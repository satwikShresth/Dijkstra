/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *Date: 6/1/2022
 *
 *code file for heap
 *has all the prototype of functions present in the file
 *
 *
 */
//heapsort Sort
//Sort using a heap data structure
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

//__________________________________________________________________________________________________________//
//Make a new heap
heap* makeHeap(int capacity){
  heap* constructor = (heap*) malloc(sizeof(heap));
  constructor->data = (heapNode**) malloc(capacity * sizeof(struct heapNode*));
  constructor->position = (int*) malloc(capacity * sizeof(int*));
  constructor->maxSize = capacity;
  constructor->currentSize=0;
  return constructor;
  }

//__________________________________________________________________________________________________________//
//Create a node for the heap
heapNode* makeHeapNode(heap* H,int v, int distance){
  heapNode* node = (heapNode*) malloc(sizeof(heapNode*));
  node->v = v;
  node->distance = distance;
  H->currentSize++;
  return node;
}

//__________________________________________________________________________________________________________//
//Is the heap empty?
char empty(heap* H){
  if(H->currentSize == 0)
    return 0;
  return 1;
}

//__________________________________________________________________________________________________________//
//What is the min?
heapNode* min(heap* H){
  if(H->currentSize ==2 && H->data[0]->distance > H->data[1]->distance)
    swap(H,1,0);

  return H->data[0];
}

//__________________________________________________________________________________________________________//
int pickSmallerChild(heap* H, int rightChild, int leftChild,int i){
  if(H->data[i]->distance > H->data[leftChild]->distance)
    return leftChild;
  if(H->data[i]->distance > H->data[rightChild]->distance)
    return rightChild;
  return i;
}

//__________________________________________________________________________________________________________//
//Downheap a value at index i
void downHeap(heap* H, int i){
  int leftIndex = leftChild(i);
  int rightIndex = rightChild(i);

  if (leftIndex >= H->currentSize-1 || rightIndex >= H->currentSize){
    return;
  }

  int minIndex = pickSmallerChild(H,rightIndex,leftIndex,i);

  if(minIndex != i){
    heapNode *smallestNode = H->data[minIndex];
    heapNode *iNode = H->data[i];
    H->position[smallestNode->v] = i;
    H->position[iNode->v] = minIndex;
    swap(H,i,minIndex);
    downHeap(H,minIndex);
  }
  return;
}

//__________________________________________________________________________________________________________//
//Get Index of Parent
int parent(int n){
  return (n-1)/2;
}

//__________________________________________________________________________________________________________//
//Get index of Left Child
int leftChild(int n){
  return ((n+1)*2)-1;
}

//__________________________________________________________________________________________________________//
//Get index of Right Child
int rightChild(int n){
  return (n+1)*2;
}

//__________________________________________________________________________________________________________//
//input:  two integers adress of array and teh heap
//output: none
//side: swaps the between both the pointers
void swap(heap* H, int i, int j){
  heapNode* temp = H->data[i];
  H->data[i] = H->data[j];
  H->data[j] = temp;
}

//__________________________________________________________________________________________________________//
//input:  pointer to heap
//output: node
//side: deletes the minimum
void deleteMin(heap* H){
	swap(H,0,H->currentSize-1);
  H->currentSize--;
  downHeap(H,0);
  if(H->currentSize-1 >= 2)
    if(H->data[0]->distance > H->data[H->currentSize-1]->distance)
      swap(H,0,H->currentSize-1);
}

//__________________________________________________________________________________________________________//
//input:  pointer to heap
//output: none
//side: frees the heap
void removeHeap(heap* H){
  removeHeapData(H);
  free(H->data);
  free(H->position);
  free(H);
}

//__________________________________________________________________________________________________________//
//input:  pointer to heap
//output: none
//side: frees the heap data
void removeHeapData(heap* H){
  for(int i =0;i<H->currentSize;i++)
    free(H->data[i]);
}

//__________________________________________________________________________________________________________//
//input:  pointer to heap
//output: none
//side: prints the heap
void printHeap(heap* H) {
  printf("Heap Current Size: %d\n",H->currentSize);
  printf("Contents :\n" );
  for(int i =0; i < H->currentSize;i++){
    printf("distance-> %d--- Vertex-> %d \n" ,H->data[i]->distance,H->data[i]->v);
    }
  printf("\n");
  }

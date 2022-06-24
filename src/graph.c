/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *Date: 6/1/2022
 *graph code file
 *
 *
 */
#include "graph.h"

//__________________________________________________________________________________________________________//
graph* makeGraph(int num){
  graph* G = (graph*) malloc(sizeof(G));
  G->numberOfVertices = num;
  G->array = calloc(num,sizeof(list));
  for(int i =0;i<num;i++){
    G->array[i] = (list*) malloc(sizeof(list*));
    G->array[i]->src = i;
  }
  return G;
}

//__________________________________________________________________________________________________________//
void insertEdge(graph* G, int fromEdge, int toEdge, int weight){
  listNode* node = makeGraphNode(toEdge, weight);
  node->next = G->array[fromEdge]->head;
  G->array[fromEdge]->head = node;
}

//__________________________________________________________________________________________________________//
listNode* makeGraphNode(int toEdge, int weight){
  listNode* node = (listNode*) malloc(sizeof(node));
  node->destiantion = toEdge;
  node->weight = weight;
  node->next = NULL;
  return node;
}

//__________________________________________________________________________________________________________//
void printGraph(graph* G) {
  printf("Number of vertices: %d\n",G->numberOfVertices);
  printf("Contents :\n" );
  for(int i =0;G->array[i];i++){
    printf("---distance-> %d---\n" ,G->array[i]->src);
    for(listNode* item = G->array[i]->head;item;item= item->next){
      printf("---to-> %d---weight-> %d\n" ,item->destiantion,item->weight);
    }
    }
  printf("\n");
  }

//__________________________________________________________________________________________________________//
void removeGraph(graph* G){
  for(int i = 0;G->array[i]; i++){
    removeGraphDataNodes(G->array[i]->head);
    free(G->array[i]);
  }
  free(G->array);
  free(G);
}

//__________________________________________________________________________________________________________//
void removeGraphDataNodes(listNode* head){
  for(listNode* curr = head;head;curr =head){
    head = head->next;
    curr =NULL;
    free(curr);
  }
}
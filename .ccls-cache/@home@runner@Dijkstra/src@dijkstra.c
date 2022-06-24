/*
 *
 *
 *Name: Satwik Shresth
 *platform: replut(*nix)
 *
 *main file
 *
 *Aknoledgement: used help from geeksforgeeks for understanding the algorithum
 *
 */
#include"dijkstra.h"

//__________________________________________________________________________________________________________//
//input:  pointer to file
//output: pointer to a graph
//side: creates and fills the graph
graph* loadFile(const char *filename){

  FILE *fp;
  int ret;
  int size;

  if ( !(fp = fopen(filename, "r")) )
        return NULL;
  ret = fscanf(fp, "%d\n",&size);
  graph* G = makeGraph(size);
  
  for(int i =0;1;i++){
    int fromEdge;
    int toEdge;
    int weight;
    ret = fscanf(fp, "%d %d %d\n",&fromEdge, &toEdge, &weight);
    if(ret == EOF){
      break;
      }
    insertEdge(G,fromEdge,toEdge,weight);
  }
  
  fclose(fp);
  return G;
}

//__________________________________________________________________________________________________________//
int main(int argv, char** argc){
  
  graph* G = loadFile(argc[2]);
  printf("Running Dijksta’s Algorithm\n");
  printf("Input File: %s\n",argc[2]);
  dijkstra(G,atoi(argc[1]));
  removeGraph(G);
}

//__________________________________________________________________________________________________________//

//input:  pointer to heap
//output: none
//side: updates teh heap
void update(heap* H,int v, int distance){
	int i = H->position[v];
	H->data[i]->distance = distance;

	while (i && H->data[i]->distance < H->data[(i - 1) / 2]->distance){
		H->position[H->data[i]->v] = parent(i);
		H->position[H->data[(i-1)/2]->v] = i;
		swap(H,i,parent(i));
    
		i = parent(i);
	}
}

//__________________________________________________________________________________________________________//

//input:  pointer to an array
//output: none
//side: prints teh heap
void printArray(int distance[], int n)
{
    for (int i = 0; i < n; ++i){
      if(distance[i] != MAX)
      printf("Path to Node %d is %d\n",i,distance[i]);
      if(distance[i] == MAX)
      printf("Path to Node %d is infinity\n",i);
    }
}
//__________________________________________________________________________________________________________//

//input:  pointer to graph and the point to start
//output: none
//side: calculates and prints teh required number of steps needed
void dijkstra(graph* G, int start){
	int V = G->numberOfVertices;
	int distance[V];

	heap* Q = makeHeap(V);

	for (int i=0; i < V; i++){
    distance[i]= MAX;
    if(i==start)
      distance[start]=0;
    Q->data[i] = makeHeapNode(Q,i,distance[i]);
    Q->position[i] = i;
	}
  update(Q,start,distance[start]);
  
  printf("Start Node: %d\n",start);
	for(heapNode* node =min(Q);empty(Q);node =min(Q)){
		deleteMin(Q);
    int u = node->v;
		for(listNode* valuePointer = G->array[u]->head;valuePointer != NULL;valuePointer=valuePointer->next){
      int v = valuePointer->destiantion;
      if(distance[u] != MAX && distance[v] > distance[u] + valuePointer->weight){
        distance[v] = distance[u] + valuePointer->weight;
        update(Q,v,distance[v]);
      }
		}
  }
  printArray(distance,V);
  removeHeap(Q);
}
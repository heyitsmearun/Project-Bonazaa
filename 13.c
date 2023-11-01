/*
   Implementation of Graph using Array
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// adjacency list node
struct Node {
   int vertex;
   struct Node* next;
};

// adjacency list
struct List {
   struct Node *head;
};

// graph structure
struct Graph {
   int V;
   struct List *array;
};

// create a new adjacency list node
struct Node* newNode(int vertex) {
   struct Node* new = (struct Node*) malloc(sizeof(struct Node));
   new->vertex = vertex;
   new->next = NULL;
   return new;
}

// create a new graph with V vertices
struct Graph* createGraph(int V) {
   struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
   graph->V = V;

   // create an array of adjacency lists
   graph->array = (struct List*) malloc(V * sizeof(struct List));

   // initialize each adjacency list
   int i;
   for(i = 0; i < V; i++) {
      graph->array[i].head = NULL;
   }

   return graph;
}

// add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
   // add edge from src to dest
   struct Node* new = newNode(dest);
   new->next = graph->array[src].head;
   graph->array[src].head = new;

   // add edge from dest to src
   new = newNode(src);
   new->next = graph->array[dest].head;
   graph->array[dest].head = new;
}

// print the graph
void printGraph(struct Graph* graph) {
   int i;
   for(i = 0; i < graph->V; i++) {
      struct Node* ptr = graph->array[i].head;
      printf("Vertex %d: ", i);
      while(ptr) {
         printf("%d -> ", ptr->vertex);
         ptr = ptr->next;
      }
      printf("NULL\n");
   }
}

int main() {
   int V, E, i, src, dest;

   printf("Enter the number of vertices in the graph: ");
   scanf("%d", &V);

   struct Graph* graph = createGraph(V);

   printf("Enter the number of edges in the graph: ");
   scanf("%d", &E);

   for(i = 0; i < E; i++) {
      printf("Enter the source and destination vertices of edge %d: ", i+1);
      scanf("%d %d", &src, &dest);
      addEdge(graph, src, dest);
   }

   printf("\nGraph:\n");
   printGraph(graph);

   return 0;
}

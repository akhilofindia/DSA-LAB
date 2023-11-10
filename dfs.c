#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};
// Structure to represent the adjacency list of the graph
struct Graph {
    int V;              // Number of vertices
    struct Node** adj;  // Array of adjacency lists
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}
// Function to add an edge between two vertices in the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}
// DFS recursive function
void DFSUtil(struct Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);
    struct Node* temp = graph->adj[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}
// Function to perform Depth-First Search (DFS)
void DFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    DFSUtil(graph, startVertex, visited);
    free(visited);
}
// Driver code
int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    printf("Depth-First Traversal starting from vertex 0: ");
    DFS(graph, 0);
    free(graph);
    return 0;
}

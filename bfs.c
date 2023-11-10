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
// Function to perform Breadth-First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    // Create a queue for BFS
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;
    visited[startVertex] = true;
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        // Traverse all adjacent vertices of the current vertex
        struct Node* temp = graph->adj[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(queue);
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
    printf("Breadth-First Traversal starting from vertex 0: ");
    BFS(graph, 0);
    free(graph);
    return 0;
}

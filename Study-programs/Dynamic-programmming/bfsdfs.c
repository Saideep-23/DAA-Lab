#include <stdio.h>
#include <stdlib.h>

// Function to perform DFS for topological sorting and cycle detection
int topologicalSortDFSUtil(int v, int numVertices, int adjMatrix[][numVertices], int* visited, int* stack, int* index) {
    visited[v] = 1;

    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[v][i]) {
            if (!visited[i]) {
                if (topologicalSortDFSUtil(i, numVertices, adjMatrix, visited, stack, index) == -1) {
                    return -1; // Cycle detected
                }
            } else if (visited[i] == 1) {
                return -1; // Back edge detected, indicating a cycle
            }
        }
    }

    visited[v] = 2; // Mark as visited and processed
    stack[(*index)++] = v;
    return 0;
}

// Function to perform topological sort using DFS and detect cycles
int topologicalSort(int numVertices, int adjMatrix[][numVertices]) {
    int* visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; ++i)
        visited[i] = 0;

    int* stack = (int*)malloc(numVertices * sizeof(int));
    int index = 0; // Initialize index to 0

    for (int v = 0; v < numVertices; ++v) {
        if (visited[v] == 0) {
            if (topologicalSortDFSUtil(v, numVertices, adjMatrix, visited, stack, &index) == -1) {
                free(visited);
                free(stack);
                printf("Cycle detected. Topological sorting is not possible.\n");
                return 1;
            }
        }
    }

    for (int i = index - 1; i >= 0; --i)
        printf("%d ", stack[i]);
    printf("\n");

    free(visited);
    free(stack);
    return 0;
}

// Function to perform topological sort using BFS and detect cycles
int topologicalSortBFS(int numVertices, int adjMatrix[][numVertices]) {
    int inDegree[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        inDegree[i] = 0;
        for (int j = 0; j < numVertices; ++j) {
            inDegree[i] += adjMatrix[j][i];
        }
    }

    int queue[numVertices];
    int front = -1, rear = -1;
    for (int i = 0; i < numVertices; ++i) {
        if (inDegree[i] == 0)
            queue[++rear] = i;
    }

    int* visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; ++i)
        visited[i] = 0;

    int count = 0; // Count of visited vertices

    while (front != rear) {
        int v = queue[++front];
        printf("%d ", v);
        visited[v] = 1;
        count++;

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[v][i]) {
                if (--inDegree[i] == 0 && !visited[i])
                    queue[++rear] = i;
            }
        }
    }

    if (count != numVertices) {
        free(visited);
        printf("Cycle detected. Topological sorting is not possible.\n");
        return 1;
    }

    free(visited);
    return 0;
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int adjMatrix[numVertices][numVertices];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("DFS Topological Sort: ");
    if (topologicalSort(numVertices, adjMatrix) == 0) {
        printf("No cycle detected. Topological sorting is possible.\n");
    }

    printf("BFS Topological Sort: ");
    if (topologicalSortBFS(numVertices, adjMatrix) == 0) {
        printf("\nNo cycle detected. Topological sorting is possible.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10

int* bellmanFord(int graph[MAX_VERTICES][MAX_VERTICES], int source, int vertices) {
    int* distances = (int*)malloc((vertices + 1) * sizeof(int));
    distances[0] = 0;

    for (int i = 1; i <= vertices; i++)
        distances[i] = (i == source) ? 0 : INT_MAX;

    for (int k = 1; k <= vertices - 1; k++) {
        for (int u = 1; u <= vertices; u++) {
            for (int v = 1; v <= vertices; v++) {
                if (graph[u][v] != INT_MAX && distances[u] != INT_MAX && distances[v] > distances[u] + graph[u][v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }

    return distances;
}

int main() {
    int vertices, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    int* distances = bellmanFord(graph, source, vertices);

    printf("Distance from %d to:\n", source);
    for (int i = 1; i <= vertices; i++) {
        printf("\t%d: %d\n", i, distances[i]);
    }

    return 0;
}

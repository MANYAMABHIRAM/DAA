#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int key[], int mst[], int n)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void prims(int **graph, int n)
{
    int parent[n], key[n], mst[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = min(key, mst, n);
        mst[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[u][j] && mst[j] == 0 && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    int total_cost = 0;
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
        total_cost += graph[i][parent[i]];
    }
}

int main()
{
    int n;
    printf("Enter the no.of vertices:");
    scanf("%d", &n);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    prims(graph, n);
}

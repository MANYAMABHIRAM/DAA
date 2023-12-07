#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int dist[], int spt[], int n)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; i++)
    {
        if (spt[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstras(int **graph, int n)
{
    int src;
    printf("Enter source of vertex:");
    scanf("%d", &src);
    int spt[n], dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        spt[i] = 0;
    }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u = min(dist, spt, n);
        spt[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (spt[j] == 0 && graph[u][j] && (graph[u][j] + dist[u] < dist[j]))
            {
                dist[j] = graph[u][j] + dist[u];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", dist[i]);
    }
}
int main()
{
    int n;
    printf("Enter no.of vertices:");
    scanf("%d", &n);
    int **graph = (int **)malloc(n * (sizeof(int *)));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter adjacent matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    dijkstras(graph, n);
}

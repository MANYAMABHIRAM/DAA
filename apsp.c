#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n;
    printf("Enter no.of vertices:");
    scanf("%d", &n);
    int x;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            if (x == -1)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = x;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((graph[i][k] + graph[k][j] < graph[i][j]) && graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    printf("The shortest path between all pairs: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

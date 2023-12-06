#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float arr1[], float arr2[], float arr3[], float low, float high)
{
    for (int i = low; i < high; i++)
    {
        for (int j = i + 1; j < high; j++)
        {
            if (arr1[i] < arr1[j])
            {
                swap(&arr1[i], &arr1[j]);
                swap(&arr2[i], &arr2[j]);
                swap(&arr3[i], &arr3[j]);
            }
        }
    }
}

void knapsack(float profit[], float weight[], float capacity, int n)
{
    float contains[n], tp = 0;
    float w = capacity;
    for (int i = 0; i < n; i++)
        contains[i] = 0.0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (weight[i] > w)
            break;
        else
        {
            contains[i] = 1.0;
            tp += profit[i];
            w -= weight[i];
        }
    }
    if (i < n)
    {
        contains[i] = w * 1.0 / weight[i];
        tp += contains[i] * profit[i];
    }
    printf("Array of containing:");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", contains[i]);
    }
    printf("\nMaximum profit:%f\n", tp);
}

int main()
{
    int n;
    printf("Enter no. of blocks:");
    scanf("%d", &n);
    float profit[n], weight[n], ratio[n];
    printf("Enter profit values:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &profit[i]);
    }
    printf("Enter weight values:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (profit[i] * 1.0) / weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", ratio[i]);
    }
    printf("\n");
    sort(ratio, profit, weight, 0, n);
    printf("Enter total capacity:");
    float capacity;
    scanf("%f", &capacity);
    knapsack(profit, weight, capacity, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int p = arr[high];
    int l = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < p)
        {
            l++;
            swap(&arr[l], &arr[j]);
        }
    }
    l++;
    swap(&arr[l], &arr[high]);
    return l;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int main()
{
    int arr[9] = {10, 8, 11, 2, 1, 5, 8, 4, 3};
    quicksort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        printf("%d  ", arr[i]);
    }
}

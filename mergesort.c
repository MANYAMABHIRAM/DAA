#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[i + m + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n);
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
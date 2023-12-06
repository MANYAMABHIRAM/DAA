#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int low = l - 1;

    for (int i = l; i <= r - 1; i++) {
        if (arr[i] <= pivot) {
            low++;
            swap(&arr[low], &arr[i]);
        }
    }

    swap(&arr[low + 1], &arr[r]);
    return low + 1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pivot = partition(arr, l, r);

        if (pivot - l == k - 1)
            return arr[pivot];

        if (pivot - l > k - 1)
            return kthSmallest(arr, l, pivot - 1, k);

        return kthSmallest(arr, pivot + 1, r, k - pivot + l - 1);
    }

    return -1; 
}

int main() {
    int n, k;
    printf("Enter the length of array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K value:");
    scanf("%d", &k);

    int result = kthSmallest(arr, 0, n - 1, k);

    if (result != -1)
        printf("The %dth smallest element is %d\n", k, result);
    else
        printf("Invalid value of k\n");

    return 0;
}

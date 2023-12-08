#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k, int i){
    for (int j = 1; j < k; j++){
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
            return 0;
    }
    return 1;
}

void nqueens(int *x, int k, int n){
    for (int i = 1; i <= n; i++){
        if (place(x, k, i) == 1){
            x[k] = i;
            if (k == n){
                for (int p = 1; p <= n; p++)
                    printf("%d ", x[p]);
                printf("\n");
            }
            else
                nqueens(x, k+1, n);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    int x = (int)malloc((n+1)*sizeof(int));
    for (int i = 0; i <= n; i++)
        x[i] = 0;
    nqueens(x, 1, n);
}

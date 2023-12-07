#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    printf("Enter no.of coins:");
    int n;
    scanf("%d", &n);
    int coins[n];
    printf("Enter no.of coins:");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    printf("Enter total amount:");
    int amount;
    scanf("%d", &amount);
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++)
        dp[i] = INT_MAX;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = (dp[i - coins[j]] + 1 < dp[i]) ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
    }
    if (dp[amount] != INT_MAX)
    {
        printf("Minimum coins:%d", dp[amount]);
    }
    else
    {
        printf("No possibilities");
    }
}

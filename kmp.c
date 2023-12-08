#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char *pattern, int M, int *lps)
{
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < M)
    {
        // printf("%d  %d\n", i, len);
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        printf("%d\t", lps[i]);
    }
}

void KMPSearch(char *pattern, char *text)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int *lps = (int *)malloc(sizeof(int) * m);

    computeLPSArray(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    free(lps);
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMPSearch(pattern, text);

    return 0;
}

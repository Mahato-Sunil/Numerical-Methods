#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float aug_mat[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* 1. Reading number of unknowns */
    printf("Enter Number of Variables : ");
    scanf("%d", &n);

    /* 2. Reading Augmented Matrix */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("aug_mat[%d][%d] = ", i, j);
            scanf("%f", &aug_mat[i][j]);
        }
    }
    /* Applying Gauss Elimination */
    for (i = 1; i <= n - 1; i++)
    {
        if (aug_mat[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = i + 1; j <= n; j++)
        {
            ratio = aug_mat[j][i] / aug_mat[i][i];

            for (k = 1; k <= n + 1; k++)
            {
                aug_mat[j][k] = aug_mat[j][k] - ratio * aug_mat[i][k];
            }
        }
    }

    /* Obtaining Solution by Back Subsitution */
    x[n] = aug_mat[n][n + 1] / aug_mat[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        x[i] = aug_mat[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - aug_mat[i][j] * x[j];
        }
        x[i] = x[i] / aug_mat[i][i];
    }
    
    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return (0);
}
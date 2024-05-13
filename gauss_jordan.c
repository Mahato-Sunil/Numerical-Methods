#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define SIZE 10

int main()
{
    float aug_mat[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of variables: ");
    scanf("%d", &n);

    /* 2. Reading Augmented Matrix */
    printf("Enter coefficients of Augmented Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("aug_mat[%d][%d] = ", i, j);
            scanf("%f", &aug_mat[i][j]);
        }
    }
    /* Applying Gauss Jordan Elimination */
    for (i = 1; i <= n; i++)
    {
        if (aug_mat[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = aug_mat[j][i] / aug_mat[i][i];
                for (k = 1; k <= n + 1; k++)
                {
                    aug_mat[j][k] = aug_mat[j][k] - ratio * aug_mat[i][k];
                }
            }
        }
    }
    /* Obtaining Solution */
    for (i = 1; i <= n; i++)
    {
        x[i] = aug_mat[i][n + 1] / aug_mat[i][i];
    }
    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return (0);
}
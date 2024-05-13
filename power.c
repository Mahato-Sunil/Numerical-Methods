#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

void matrixVectorMult(float matrix[][SIZE], float vector[], float result[], int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = 0.0;
        for (int j = 0; j < size; j++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

float normalizeVector(float vector[], int size)
{
    float maxElement = fabs(vector[0]);
    for (int i = 1; i < size; i++)
    {
        if (fabs(vector[i]) > maxElement)
        {
            maxElement = fabs(vector[i]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        vector[i] /= maxElement;
    }
    return maxElement;
}

int main()
{
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float lambda_new, lambda_old = 1, error;
    int n, step = 1;

    printf("Enter Order of Matrix: \t");
    scanf("%d", &n);

    printf("Enter Tolerable Error: \t");
    scanf("%f", &error);

    printf("Enter Coefficient of Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" Matrix Row [%d] : ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter Initial Guess Vector:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    while (1)
    {
        matrixVectorMult(a, x, x_new, n);

        lambda_new = normalizeVector(x_new, n);

        if (fabs(lambda_new - lambda_old) <= error)
        {
            break;
        }

        lambda_old = lambda_new;
        step++;
        for (int i = 0; i < n; i++)
        {
            x[i] = x_new[i];
        }
    }

    printf("\n\n Iterations :\t %d:\n", step);
    printf("Eigen Value  \t %f\n", lambda_new);
    printf("Eigen Vector:\n");
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%f\t", x_new[i]);
    }
    printf("]");
    return 0;
}

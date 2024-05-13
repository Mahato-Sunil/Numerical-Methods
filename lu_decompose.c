#include <stdio.h>

#define N 3 // Size of the matrix

// Function to perform LU decomposition
void lu_decomposition(double A[N][N], double L[N][N], double U[N][N], double b[N], double x[N])
{
    int i, j, k;

    // Initialize matrices L and U
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
                L[i][j] = 1; // Diagonal elements of L are 1
            else
                L[i][j] = 0;

            U[i][j] = A[i][j];
        }
    }

    // Perform LU decomposition
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            double factor = U[j][i] / U[i][i];
            L[j][i] = factor;
            for (k = i; k < N; k++)
            {
                U[j][k] -= factor * U[i][k];
            }
        }
    }

    // Solve for the solution vector x using LU decomposition
    // Forward substitution for Ly = b
    double y[N];
    for (i = 0; i < N; i++)
    {
        y[i] = b[i];
        for (j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Backward substitution for Ux = y
    for (i = N - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (j = i + 1; j < N; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

// Function to print a matrix
void print_matrix(double mat[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%.4f\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to print a vector
void print_vector(double vec[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("\t%.4f\n", vec[i]);
    }
    printf("\n");
}

int main()
{
    double A[N][N] = {{5, 4, 3},
                      {7, 4, -1},
                      {8, -5, 5}}; // Input matrix

    double b[N] = {28, 20, 24}; // Right-hand side vector
    double L[N][N], U[N][N];    // Matrices for LU decomposition
    double x[N];                // Solution vector

    // Perform LU decomposition and solve the system
    lu_decomposition(A, L, U, b, x);

    printf("Lower Trangular Matrix :\n");
    print_matrix(L);

    printf("\nUpper Trangular Matrix :\n");
    print_matrix(U);

    printf("\nSolution vector [x]:\n");
    print_vector(x);

    return 0;
}
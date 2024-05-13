#include <stdio.h>
#include <math.h>

// Function to calculate the value of the equation
double f(double x)
{
    return pow(x, 3) - 3 - 7 * pow(x, 2) + 8 * x - 3;
}

// Function to calculate the derivative of the equation
double g(double x)
{
    return 3 * pow(x, 2) - 14 * x + 8;
}

int main()
{
    double x0, x1, E;
    int i, n;

    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    printf("Enter the error tolerance: ");
    scanf("%lf", &E);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &n);

    i = 0;
    while (fabs(f(x0)) > E)
    {
        if (fabs(g(x0)) < 0.000005)
        {
            printf("\nError: First derivative approx. to 0\n");
            return -1;
        }

        x1 = x0 - f(x0) / g(x0);
        x0 = x1;
        i++;

        if (i > n)
        {
            printf("\nError: Not convergent\n");
            return -1;
        }
    }

    printf("Real positive root: %f\n", x0);
    printf("Number of iterations: %d\n", i);

    return 0;
}

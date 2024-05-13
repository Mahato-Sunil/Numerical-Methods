#include <stdio.h>
#include <math.h>

// function declaration
double func(double x)
{
    return exp(sin(x)) - log(x);
}

// simpsons function to solve the problem
double simpsons(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    double x;

    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        sum += (i % 3 == 0) ? 2 * func(x) : 3 * func(x);
    }

    return sum * 3 * h / 8;
}

// main function
int main()
{
    double a, b;
    int n;

    printf("\nEnter the Limits of the Integration:\t");
    scanf("%lf %lf", &a, &b);

    if (a >= b)
    {
        printf("\nError: Lower limit should be less than upper limit.\n");
        return 1;
    }

    printf("\nEnter the number of subintervals: \t");
    scanf("%d", &n);

    if (n % 3 != 0)
    {
        printf("\nError: The number of subintervals should be a multiple of 3.\n");
        return 1;
    }

    // calling the function
    double result = simpsons(a, b, n);
    printf("\nThe solution is : %.6lf\n", result);
    return 0;
}

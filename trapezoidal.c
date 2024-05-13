#include <stdio.h>
#include <math.h>
#define N 100

// trapezoidal function
double trapezoidal(double a, double b, int n)
{
    double y[N], sum;
    double interval = (b - a) / n;

    // the function is f(x) = 1 / (1 + pow(x, 2));
    // getting the x values from the given function
    for (int i = 0; i <= n; i++)
    {
        y[i] = 1 / (1 + pow(i, 2));
        printf("%lf \t", y[i]);
    }

    sum = y[0] + y[n];
    for (int i = 1; i < n; i++)
        sum = sum + 2 * y[i];
    sum = sum * interval / 2;
    return sum;
}

// main function
int main()
{
    // asking for the user input
    double a, b, result;
    int n;
    printf("Enter the limit of the integration : \t");
    scanf("%lf %lf", &a, &b);

    printf("Enter the number of Intervals : \t");
    scanf("%d", &n);

    // passing the values to the functions
    result = trapezoidal(a, b, n);
    printf("\nSolution of the Function : \t %lf", result);
    return 0;
}

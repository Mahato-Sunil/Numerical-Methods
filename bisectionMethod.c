#include <stdio.h>
#include <math.h>

//  change the return expressinon as per equation
double function(double x)
{
    return x * sin(x) + cos(x);
}

// bisection function
double bisection(double a, double b, double c, double E)
{
    int iteration = 0;
    if (function(a) * function(b) > 0)
    {
        printf("\n Error: No Root in given Interval.");
        return -1;
    }
    // main calculations
    do
    {
        c = (a + b) / 2;
        if (function(c) * function(a) > 0)
            a = c;
        else
            b = c;
        iteration++;
    } while (fabs(function(c)) > E);
    printf("\n No. of Iteration = %d \n", iteration);
    return c;
}

// driver code
int main()
{
    double a, b, c, E, root;
    printf("Enter the Initial Interval : \t");
    scanf("%lf %lf", &a, &b);
    printf("Enter Error Tolerance : \t ");
    scanf("%lf", &E);
    root = bisection(a, b, c, E);
    if (root != -1)
        printf("Root of Function : \t %f", root);
    return 0;
}
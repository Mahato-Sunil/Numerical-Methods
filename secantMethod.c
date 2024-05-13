#include <stdio.h>
#include <math.h>

double f(double x)
{
    return exp(-x) * cos (x);
}

int main()
{
    double a, b, c, E;
    int i, n;
    printf("Enter Initial Guesses (a, b) :\t");
    scanf("%lf %lf", &a, &b);
    printf("Enter Error Tolerance : \t");
    scanf("%lf", &E);
    printf("Enter Maximum Iteration :\t");
    scanf("%d", &n);
    i = 0;
    do
    {
        if (fabs(f(b) - f(a)) < 0.000005)
        {
            printf("Division by zero error!");
            return 0;
        }

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        a = b;
        b = c;
        i = i + 1;
        if (i > n)
        {
            printf("Error: Not Convergent!");
            return 0;
        }
    } while (fabs(f(c)) > E);
    printf("Real Root : %f", c);
    printf("\n No. of Iteration : %d", i);
    return 0;
}

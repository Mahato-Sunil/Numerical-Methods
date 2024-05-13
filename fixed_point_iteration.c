#include <stdio.h>
#include <math.h>

/* Define function f(x) which is to be solved */
#define f(x) cos(x) - 3 * x + 1
/* Write f(x) as x = g(x) and define g(x) here */
#define g(x) (1 + cos(x)) / 3

int main()
{
    int i = 1, N;
    float x0, x1, E;
    
    /* Inputs */
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &E);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);
    /* Implementing Fixed Point Iteration */
   do
    {
        x1 = g(x0);
        i = i + 1;
        if (i > N)
        {
            printf("Not Convergent.");
            return -1;
        }

        x0 = x1;

    } while (fabs(f(x1)) > E);

    printf("\nRoot is :  %f", x1);
    printf("\n Number of Iteration : %d", i);
    return 0;
}
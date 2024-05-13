#include <stdio.h>

// calculating the value of p
float p_val(float p, int n)
{
    float temp = p;
    for (int i = 1; i < n; i++)
        temp = temp * (p - i);
    return temp;
}

// calculating the factorial of the number
int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    float x[20], y[20][20];
    int i, j, n;
    float val;

    printf("Enter number of data? ");
    scanf("%d", &n);
    printf("Enter data:");
    for (i = 0; i < n; i++)
    {
        printf("\n At %d  [x, y] : \t", i);
        scanf("%f %f", &x[i], &y[i][0]);
    }

    printf("Enter the value to be interpolated : ");
    scanf("%f", &val);

    /* Generating Gauss's Forward Difference Table */
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    /* Displaying Gauss's Forward Difference Table */
    printf("\nGAUSS'S FORWARD DIFFERENCE TABLE\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    // interpolating the table
    float sum = y[0][0];
    float p = (val - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
        sum += p_val(p, i) * y[0][i] / fact(i);

    printf("\nInterpolated value at %.2f is %.4f\n", val, sum);
    return 0;
}

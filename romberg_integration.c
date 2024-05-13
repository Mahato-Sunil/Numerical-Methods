#include <stdio.h>
#include <math.h>

#define FUNC(x) 1 / (1 + x)

float calculateIntegral(float x0, float xn, int p, int q);

int main()
{
    float lowerLimit, upperLimit;
    int p, q;

    printf("Enter lower and upper limit: ");
    scanf("%f %f", &lowerLimit, &upperLimit);

    printf("Enter p and q for T(p,q): ");
    scanf("%d %d", &p, &q);

    float result = calculateIntegral(lowerLimit, upperLimit, p, q);

    printf("Romberg estimate of integration = %f\n", result);

    return 0;
}

float calculateIntegral(float x0, float xn, int p, int q)
{
    float t[10][10], h, sm, sl, a;
    int i, k, c, r, m;

    h = xn - x0;
    t[0][0] = h / 2 * (FUNC(x0) + FUNC(xn));

    for (i = 1; i <= p; i++)
    {
        sl = pow(2, i - 1);
        sm = 0;

        for (k = 1; k <= sl; k++)
        {
            a = x0 + (2 * k - 1) * h / pow(2, i);
            sm += FUNC(a);
        }

        t[i][0] = t[i - 1][0] / 2 + sm * h / pow(2, i);
    }

    for (c = 1; c <= p; c++)
    {
        for (k = 1; k <= c && k <= q; k++)
        {
            m = c - k;
            t[m + k][k] = (pow(4, k) * t[m + k][k - 1] - t[m + k - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    return t[p][q];
}

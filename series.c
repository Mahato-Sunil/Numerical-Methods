#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int fact = 1;
    for (int i = n; i > 0; i--) {
        fact = fact * i;
    }
    return fact;
}


int main() {
    int x;
    int n;
    float sum=1;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter the number of terms (n) in the series: ");
    scanf("%d", &n);

// calculating series 

     for (int i = 1; i <= n; ++i) {
        sum += pow(x, i) / factorial(i);
    }

    printf("Sum of Series = %f", sum);
    return 0;
}

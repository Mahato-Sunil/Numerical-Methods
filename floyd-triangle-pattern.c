#include <stdio.h>
int main()
{
    int i, j, k,n;
    printf(" Enter the number of rows: \t");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {

        for (k = 0; k < i - 1; k++)
        {
            printf(" ");
        }

        for (j = i; j <= n; j++)
        {
            if (j % 2 == 0)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }
}
#include<stdio.h>
#include<math.h>
int main()
{
int x, y;
float  result;
printf("Enter the value of x and y : \t");
scanf("%d %d", &x,&y);

result = (float)5*x*sqrt((x^2) + 5);

printf("The result is : %f", result);

return 0;
}
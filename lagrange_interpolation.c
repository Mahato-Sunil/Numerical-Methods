#include<stdio.h>
int main()
{
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;
	
	 /* Input Section */
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 for(i=1;i<=n;i++)
	 {
        printf("At %d [x, y] : \t", i);
        scanf("%f %f", &x[i], &y[i]);
	 }

	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);
     
	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, yp);
}
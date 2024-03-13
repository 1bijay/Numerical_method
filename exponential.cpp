#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int n,i,j,k;
float a=0,b=0,r,x[10],y[10],sx=0,slogy=0,sxy=0,sxz=0;
printf("Enter the number of points\n");
scanf("%d",&n);
printf("Enter the value of x and fx\n");
for(i=0;i<n;i++)
{
scanf("%f%f",&x[i],&y[i]);
}
for(i=0;i<n;i++)
{
sx=sx+x[i];
slogy=slogy+log(y[i]);
sxy=sxy+x[i]*log(y[i]);
sxz=sxz+x[i]*x[i];
}
b=((n*sxy)-(sx*slogy))/((n*sxz)-(sx*sx));
r=(slogy/n)-(b*sx/n);
a=exp(r);
printf("Fitted curve is:y=%fe^%fx",a,b);
return 0;

}

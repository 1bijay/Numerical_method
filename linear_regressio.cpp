#include<stdio.h>
#include<conio.h>
int main()
{
int n,i,j,k;
float a=0,b=0,x[10],y[10],sx=0,sy=0,sxy=0,sxz=0;
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
sy=sy+y[i];
sxy=sxy+x[i]*y[i];
sxz=sxz+x[i]*x[i];
}
b=((n*sxy)-(sx*sy))/((n*sxz)-(sx*sx));
a=(sy/n)-(b*sx/n);
printf("Fitted line is:%f+%fx",a,b);
return 0;

}
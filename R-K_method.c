#include <stdio.h>
#include <math.h>
#define f(x,y) 2*(x)+(y)
int main()
{

  int n;
  float x,y,xp,h;
  float m1,m2,m3,m4;
  printf("Input initial value of x and y:\n");
  scanf ("%f%f",&x,&y);
  printf("Input X-value at which Y is required :\n");
  scanf("%f",&xp);
  printf("Input  step size:\n");
  scanf("%f",&h);
  n=(int)((xp-x)/h+0.5);

  {
  		m1=f(x,y);
      m2=f(x+0.5*h,y+(m1*h*0.5));
      m3=f(x+0.5*h,y+(m2*h*0.5));
      m4=f(x+h,y+m3*h);
      x=x+h;
      y=y+((h/6)*(m1+2.0*m2+2.0*m3+m4));
    
  }
  printf("\n Value of y at xp =%0.3f is %0.3f",x,y);
  return 0;
}




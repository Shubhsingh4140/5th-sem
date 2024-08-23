#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float func(float x)
{
    return (x*x*x)-(2*x)-5;
}
/*
NAME:SHUBHANKAR SINGH SISODIA
ROLL NO:65
SECTION:D*/

void main()
{
    float x1,x2;
    float error;
    float x,y;
    float mx,x3;
    
        printf("enter the first intial guess \n");
    scanf("%f",&x1);
     printf("enter the second intial guess\n");
    scanf("%f",&x2);
    printf("enter the error\n");
    scanf("%f",&error);
    x=func(x1);
    y=func(x2);
    mx=x*y;
    printf("NAME:SHUBHANKAR SINGH SISODIA\n ROLL NO:65\nSECTION:D\n");
    
    if(mx<0)
    {
        printf("x1\t\tx2\t\tx3\n");

    do
    {
         x3=(x1+x2)/2;
         printf("%f\t%f\t%f\n",x1,x2,x3);
        if((func(x3)*func(x1))<0)
        {
            x2=x3;
        }
         else if((func(x3)*func(x1))>0)
        {
          x1=x3;
        }
        //printf("Assumed Root=%f\n",x3);

        

        
    } while (fabs(func(x3))>error);
    printf("The final Approximate Root=%f\n",x3);
    }
    else
    {
        printf("Inavlid guess\n");
    }

    

    
    



}

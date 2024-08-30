#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Shubhankar Singh Sisodia\nSection: D\nRno: 65\n\nIterations Method\n\n");
}

float f(float x)
{
    float eq = (cos(x)) - (3*x)+1;
    return eq;
}
float f1(float x)
{
    float eq=(1+cos(x))/3;
    return eq;
}
float f2(float x)
{
    float eq=acos(3*(x)-1);
    return eq;
}

float df1(float x)
{
    float eq = -(sin(x))/3;
    return eq;
}
float df2(float x)
{
    float eq=3/pow(1-pow((3*x-1),2),0.5);
    return eq;
}

void main()
{
    int count = 0;
    float a, b, e;
    float c;

    details();

    printf("Enter the value of guesses (a and b) : ");
    scanf("%f %f", &a, &b);

    printf("\nEnter error : ");
    scanf("%f", &e);
    if (f(a) * f(b) < 0)
    {
        if (fabs(f(a)) < fabs(f(b)))
        {
            a = a;
        }
        else
        {
            a = b;
        }

        printf("\nInitial guess (a) can be taken as : %f", a);
        int a1=fabs(df1(a));
        int a2=fabs(df2(a));
        
        if(a1<1||a2<1 &&a1<a2){

            printf("\nThe selected equation is =(1+cos(x))/3\n\n");

        printf("\n\nIterations\t\tPrev Val\t\t\tCurr Val\n\n");

        do
        {
            count++;
            c = f1(a);
            printf("%d\t\t\t%f\t%f\n", count, a, c);

            if (a == c)
            {
                break;
            }

            a = c;
        } while (fabs(f(c)) > e);
        printf("\nFinal approximate root after %d iterations is : %f\n", count, c);
    }
    else if(a1<1||a2<1 &&a2<a1){

        printf("\nThe selected equation is =acos(3*(x)-1)\n\n");
        printf("\n\nIterations\t\tPrev Val\t\t\tCurrent Val\n\n");

        do
        {
            count++;
            c = f2(a);
            printf("%d\t\t\t%f\t%f\n", count, a, c);

            if (a == c)
            {
                break;
            }

            a = c;
        } while (fabs(f(c)) > e);
        printf("\nFinal approximate root after %d iterations is : %f\n", count, c);
    }
    else{
    printf("Regulatory Condition Not Satisfied\n");
    }
    }
    else
    {
        printf("Invalid guess");
    }
}

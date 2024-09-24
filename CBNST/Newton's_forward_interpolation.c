#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Shubhankar Singh Sisodia\nSection: D\nRno: 65\n\nIterations Method\n\n");
}
int fact(int x)
{
    if(x==0||x==1)
        return 1;
    else
        return x*fact(x-1);
}
float u_value(float u,int x){
    if(x==0)
    return 1;
    if(x==1)
    return u;
    else{
        float answ=u;
        for(int i=1;i<x;i++){
            answ*=(answ-i);

        }
        return answ;
    }
}
int main()
{
    int size;
    printf("enter the number of arguments\n");
    scanf("%d",&size);
     int point;
        printf("enter the value of x\n");
        scanf("%d",&point);
    int x[size];
    int y[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    printf("years\tpopulation\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",x[i]);
        printf("%d",y[i]);
        printf("\n");
    }
    int diff=x[1]-x[0];
    int c=1;
    for(int i=1;i<size-1;i++)
    {
        int diffCal=x[i+1]-x[i];
        if(diffCal==diff){
            c++;
        }
    }
    if(c==size-1&&(point>x[0]&& point<x[1]))
    {
       

        int csize=size-1;
        int ny[size];
        int fx[size];
        for(int i=0;i<size;i++)
        {
            ny[i]=y[i];
        }
        int k=0;
        fx[0]=ny[0];

        while(csize!=0)
        {
            int arr[csize];
            for(int i=0;i<csize;i++)
            {
                arr[i]=ny[i+1]-ny[i];
            }
            fx[++k]=arr[0];
            for(int i=0;i<csize;i++){
                printf("%d\t",arr[i]);
            }
            printf("\n");
            for(int i=0;i<csize;i++)
            {
            ny[i]=arr[i];
            }
            csize--;


        }
        for(int i=0;i<size;i++){
            printf("%d\t",fx[i]);
        }
        float answ;
        float u=(float)(point-x[0])/diff;
        printf("%f\n",u);
        for(int i=0;i<size;i++)
        {
            answ+=(fx[i]*u_value(u,i))/fact(i);
        }
        printf("Answer=%f\n",answ);
    }
    else{
        printf("Inavlid Input \n");
    }

    
    return 0;
}

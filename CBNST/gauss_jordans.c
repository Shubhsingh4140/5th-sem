#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Shubhankar Singh Sisodia\nSection: D\nRno: 65\n\nGauss Jordans Method\n\n");
}

void main()
{
	int i,j;
    details();
	int size;
	printf("Enter size of matrix : ");
	scanf("%d",&size);
	float arr[size][size+1];

		    printf("Enter elements of matrix : ");

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			scanf("%f",&arr[i][j]);	
		}			
	}
	printf("\nAugumented matrix\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
	for(i=1;i<size;i++){

            float c=arr[i][0]/arr[0][0];
            for(j=0;j<size+1;j++){
                arr[i][j]=arr[i][j]-(arr[0][j]*c);

            }
    }
	printf("\nintermediate matrix\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
  

     float c=arr[2][1]/arr[1][1];
     float c2=arr[0][1]/arr[1][1];
        for(j=1;j<size+1;j++){
        arr[2][j]=arr[2][j]-(arr[1][j]*c);
        arr[0][j]=arr[0][j]-(arr[1][j]*c2);
        }

    

    printf("\nIntermediate  Matrix\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
   
   float c3=arr[1][2]/arr[2][2];
     float c4=arr[0][2]/arr[2][2];
        for(j=1;j<size+1;j++){
        arr[1][j]=arr[1][j]-(arr[2][j]*c3);
        arr[0][j]=arr[0][j]-(arr[2][j]*c4);
        }
        printf("\nDiagonal Matrix\n");
        for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
    float x=arr[0][3]/arr[0][0];
    int y=arr[1][3]/arr[1][1];
    int z=arr[2][3]/arr[2][2];
    printf("\nValue of x=%f\n",x);
    printf("Value of y=%d\n",y);
    printf("value of z=%d\n",z);
   
    

            
}

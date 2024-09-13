#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Shubhankar Singh Sisodia\nSection: D\nRno: 65\n\nGauss Elimination Method\n\n");
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
        for(j=1;j<size+1;j++){
        arr[2][j]=arr[2][j]-(arr[1][j]*c);}

    printf("\nUpper triangular Matrix\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
    int z=arr[size-1][size]/arr[size-1][size-1];
    int y=(arr[size-2][size]-z*arr[size-2][size-1])/arr[size-2][size-2];
    int x=(arr[size-3][size]-z*arr[size-3][size-1]-y*arr[size-3][size-2])/arr[size-3][size-3];
    printf("\nValue of x=%d\n",x);
    printf("Value of y=%d\n",y);
    printf("value of z=%d\n",z);
    

            
}

#include <stdio.h>
int main()
{
    int arr[4][4];
    for (int i=0; i<4; i++)
    {
        printf("\n");
        for (int j=0; j<4; j++)
        {
            printf("Enter element for row %d :",i+1) ; // Input for array arr
            scanf("%d",&arr[i][j]);
        }
    }

    for (int i=0; i<4; i++)
    {
        printf("\n");
        for (int j=0; j<4; j++)
        {
            printf("%d ",arr[i][j]);        // Printing array arr
        }
    }

    int n=4;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (j==n/2-1)
            {
                int temp=arr[i][j] ;
                arr[i][j]=arr[i][j+1] ;
                arr[i][j+1]=temp ;
            }
        }
    }
    printf("\n\n");

    for (int i=0; i<4; i++)
    {
        printf("\n");
        for (int j=0; j<4; j++)
        {
            printf("%d ",arr[i][j]);        // Printing array arr
        }
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int arr[3][3], brr[3][3] ;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("Enter element for row %d :",i+1) ; // Input for array arr
            scanf("%d",&arr[i][j]);
        }
    }

    for (int i=0; i<3; i++)
    {
        printf("\n");
        for (int j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);        // Printing array arr
        }
    }


    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            brr[j][i]=arr[i][j] ;            // Enter value from arr to brr
        }
    }
    printf("\n\n");

    for (int i=0; i<3; i++)
    {
        printf("\n");
        for (int j=0; j<3; j++)
        {
            printf("%d ",brr[i][j]);        // Printing Value of brr 
        }
    }
    return 0;
}
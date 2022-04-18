#include <stdio.h>
int main()
{
    int arr[3][3] ;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("Enter element for row %d :",i+1) ;
            scanf("%d",&arr[i][j]);
        }
    }

    for (int i=0; i<3; i++)
    {
        printf("\n");
        for (int j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    int count=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (i==j || i+j==2)
                count+=arr[i][j];
        }
    }
    printf("\nCount = %d",count);
    return 0;
}
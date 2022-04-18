#include <stdio.h>
int displayViaIndexing(int arr[][3][2], int, int, int) ;
int main()
{
    int arr[4][3][2]={
        {{10,11},{12,13},{14,15}},
        {{16,17},{18,19},{20,21}},
        {{22,23},{24,25},{26,27}},
        {{28,29},{30,31},{32,33}}
    };
    displayViaIndexing(arr,4,3,2) ;
    

    return 0;
}

int displayViaIndexing(int arr[][3][2], int d1, int d2, int d3)
{
    printf("displayViaIndexing\n") ;
    for (int i=0; i<d1; i++)
    {
        for (int j=0; j<d2; j++)
        {
            for (int k=0; k<d3; k++)
            {
                printf("%d ",arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
#include <stdio.h>
void displayViaIntPointer(int *,int ,int ) ;
void displayViaArrayPointer(int (*)[], int , int ) ;    // Thats how you define protype taking input of a pointer of array
void displayViaIndexing(int arr[][3],int row, int col) ;

int main()
{
    int arr[4][3]={{10,20,12},{30,40,12},{50,60,12},{70,80,12}} ;
    // displayViaIntPointer((int *)arr,4,3) ;

    displayViaArrayPointer(arr,4,3) ;

    
    // displayViaIndexing(arr,4,3) ;

    return 0;
}

void displayViaIntPointer(int *p,int row,int col)
{
    for (int i=0; i<row; i++)
    {
        printf("\n");
        for (int j=0; j<col; j++)
        {
            printf("%d ",*(p+i*col+j)) ;
        }
    }
    /*
    10(0,0) 20(0,1) 12(0,2) 
    30(1,0) 40(1,1) 12(1,2) 
    50(2,0) 60(2,1) 12(2,2) 
    70(3,0) 80(3,1) 12(3,2)
    
    i*col shifts the pointer to the end of the previous inputed row
    and then adding j shifts the pointer to the required position
    */
}

void displayViaArrayPointer(int (*p)[3], int row, int col)
{
    for (int i=0; i<row; i++)
    {
        printf("\n");
        for (int j=0; j<col; j++)
        {
            printf("%d  ",p[i][j] ) ;       // Same as Array as a pointer
        }
    }
}

void displayViaIndexing(int arr[][3], int row , int col)
{
    for (int i=0; i<row ; i++)
    {
        printf("\n");
        for (int j=0; j<col; j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
}
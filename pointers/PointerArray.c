#include <stdio.h>
int main()
{
    int arr[6]={10,20,30,40,50,60};
    for(int i=0; i<6; i++)
    {
        printf("\nElement Number : %d , Element : %d , Element Address : %u",i,arr[i],&arr[i]);
    }
    return 0;
}
#include <stdio.h>
int main()
{
    int arr[6]={10,20,30,40,50,60};
    int *p;
    int (*q)[5];
    p=arr;
    q=(int (*)[])arr;
    printf("\nthis is p=arr : %u",p);
    printf("\nthis is q=arr[0] : %u",q);

    printf("\nthis when *p : %u",*p);
    printf("\nthis when (*q)[4] : %u",(*q)[4]);

    return 0;
}
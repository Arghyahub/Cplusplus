#include <stdio.h>
/*Checking adress of a variable
then passing varaible as parameter and checking formal parameter's address*/
void fun(int);
int main()
{
    int i=10;
    int *p;
    p=&i;
    printf("value of i is :%d",i);
    printf("\naddress of i is :%u",p);
    fun(i);

}
void fun(int k)
{
    int *m;
    m=&k;
    printf("\naddress of formal parameter : %u",m);
}

// hence variable defined in function header has a different address as of the variable passed to it
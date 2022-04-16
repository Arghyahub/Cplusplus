#include<iostream>
#include<string>
using namespace std;
void saynum(int n,string arr[])
{
    if (n==0)
        return ;
    
    int digit=n%10 ;
    saynum(n/10,arr) ;
    cout<<arr[digit]<<" " ;
}

int main(){
    int n;
    cin>>n;
    string arr[10]={
        "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"} ;
    saynum(n,arr) ;

    return 0 ;
}